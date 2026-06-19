#include <bits/stdc++.h>

class vint {
public:
    using uint = uint8_t;

    vint() = default;

    template<typename T>
    explicit vint(T value) {
        std::string val_str = std::to_string(value);
        std::reverse(val_str.begin(), val_str.end());
        for (const char numeral: val_str)
            numerals.emplace_back(numeral-'0');
    }

    template <typename T>
    void mul(T value) {
        T carry {};
        for (uint8_t & numeral: numerals) {
            T result {carry};
            result += numeral*value;
            numeral = result%10;
            carry = result/10;
        }

        while (carry) {
            if (carry > 9)
                numerals.emplace_back(carry%10);
            else
                numerals.emplace_back(carry);
            carry /= 10;
        }
    }

    void print() {
        std::string val_str {};
        for (const uint8_t numeral: numerals)
            val_str += std::to_string(numeral);
        std::reverse(val_str.begin(), val_str.end());
        std::cout << val_str << "\n";
    }

    void solution() const {
        unsigned long long sum = 0;
        for (const uint8_t numeral: numerals) {
            sum += numeral;
        }
        std::cout << "\n" << "Solution: " << sum << "\n";
    }

private:
    std::vector<uint> numerals {};
};


int main() {
    vint numba1(1);

    for (int i = 1; i <= 100; ++i) {
        numba1.mul(i);
        std::cout << i << "! = "; numba1.print();
    }
    numba1.solution();

    return 0;
}