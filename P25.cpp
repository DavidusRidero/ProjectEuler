 #include <bits/stdc++.h>

namespace vint_ns {
    class vint {
    public:
        using uint = uint16_t;
        // using uint = uint32_t;

        // Empty Initialization.
        vint() : numerals{0} {}

        // Initialization with unsigned integer value.
        template<typename T,
                 typename = std::enable_if_t<std::is_integral_v<T> && std::is_unsigned_v<T>>>
        explicit vint(T value) {
            if (value == 0) {
                numerals = {0};
                return;
            }
            while (value > 0) {
                numerals.emplace_back(value % 10);
                value /= 10;
            }
        }

        // Initialization from anything that's not an uint.
        explicit vint (std::string value) {
            if (!value.empty() && value[0] == '-')
                throw std::invalid_argument("vint does not support negative values");

            if (value.empty())
                value = "0";

            std::reverse(value.begin(),value.end());

            for ( const auto numeral : value) {
                if (numeral < '0' || numeral > '9')
                    throw std::invalid_argument("vint string contains non-digit character");
                numerals.emplace_back(numeral-'0');
            }

            while (numerals.size() > 1 && numerals.back() == 0)
                numerals.pop_back();
        }

        vint& operator+= (const vint& second) {
            const size_t lar = std::max(second.numerals.size(), numerals.size());

            // Got caught out here. result's numerals is empty, and idx would have indexed out of bounds.
            numerals.resize(lar, 0);
            size_t idx {0};
            uint carry {0};

            while (idx < second.numerals.size()) {
                const uint sum = carry + numerals[idx] + second.numerals[idx];
                numerals[idx] = sum % 10;
                carry = sum / 10;
                idx++;
            }

            // Propagate carry through remaining digits (only in *this)
            while (carry && idx < lar) {
                const uint sum = carry + numerals[idx];
                numerals[idx] = sum % 10;
                carry = sum / 10;
                idx++;
            }

            if (carry)
                numerals.emplace_back(carry);

            return *this;
        }

        vint operator+ (const vint& second) const {
            vint result {*this};
            result += second;
            return result;
        }

        template<typename T,
                 typename = std::enable_if_t<std::is_integral_v<T> &&
                     std::is_unsigned_v<T>>>
        void operator*= (T mult) {
            using wide_t = uint64_t;

            wide_t carry {};
            for (auto& numeral: numerals) {
                const wide_t result = carry + static_cast<wide_t>(numeral) * mult;
                numeral = static_cast<uint>(result%10);
                carry = result/10;
            }

            while (carry) {
                numerals.emplace_back(static_cast<uint>(carry%10));
                carry /= 10;
            }

            normalise();
        }

        template<typename T,
             typename = std::enable_if_t<std::is_integral_v<T> &&
                 std::is_unsigned_v<T>>>
        vint operator*(T mult) const {
            vint result {*this};
            result *= mult;
            return result;
        }

        // TODO: vint*vint is pending.

        // This becomes a member function. Compiler silently injects object pointer *this.
        // That breaks the 2 parameter requirement.
        friend std::ostream& operator<< (std::ostream&, const vint&);

        [[nodiscard]] size_t n_size() const{
            return numerals.size();
        }

    private:
        std::vector<uint> numerals {};

        void normalise () {
            while (numerals.size() > 1 && numerals.back() == 0)
                numerals.pop_back();
        }
    };

    std::ostream& operator<< (std::ostream& os, const vint& number) {
        if (number.numerals.empty()) { os << '0'; return os; }

        for (auto it = number.numerals.rbegin(); it != number.numerals.rend(); ++it)
            os << *it;
        return os;
    }
}

int main () {
    using namespace vint_ns;
    uint64_t counter = 3;

    vint num1 {1U};
    vint num2 {1U};

    while (true) {
        const vint res = num1+num2;
        num1 = num2;
        num2 = res;
        std::cout << "F_" << counter++ << " has "<< res.n_size() << " digits.\n";
        if (res.n_size() >= 1000) break;
    }
}