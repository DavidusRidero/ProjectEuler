module;

#include <bits/stdc++.h>
export module integers;

export class integer {
public:
    static constexpr int BASE = 1'000'000'000;

    integer() = default;

    explicit integer (const std::string& number) {
        for ( int i { static_cast<int>(number.length()) }; i>0; i-=9)
            if (i>=9)
                blocks.push_back(std::stoi(number.substr(i-9,9)));
            else
                blocks.push_back(std::stoi(number.substr(0,i)));
    }

    [[nodiscard]] int safe_get (const size_t index) const {
        try {
            return blocks.at(index);
        }
        catch (const std::out_of_range&) {
            return 0;
        }
    }

    integer operator+= (const integer& second) {
        std::vector<int> result {};
        int carry {}; size_t index {};

        while (index < blocks.size() or index < second.blocks.size() or carry > 0) {
            long long sum = carry;
            sum += safe_get(index);
            sum += second.safe_get(index);

            carry = static_cast<int>(sum/BASE);
            result.push_back(static_cast<int>(sum%BASE));
            index++;
        }
        this -> blocks = std::move(result);
        return *this;
    }

    integer operator+ (const integer& second) const {
        integer result {*this};
        result += second;
        return result;
    }

    friend std::ifstream& operator>> (std::ifstream& fin, integer &number);

    void print() {
        if (blocks.empty()) { std::cout << "0\n"; return; }

        auto block = blocks.rbegin(); std::cout << *block; ++block;
        for (; block != blocks.rend(); ++block)
            std::cout << std::setw(9) << std::setfill('0') << *block << "";

        std::cout << "\n";
    }

private:
    std::vector<int> blocks {};
};