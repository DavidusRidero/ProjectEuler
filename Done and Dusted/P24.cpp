#include <bits/stdc++.h>

using ull = unsigned long long;
constexpr ull limit {1'000'000 - 1};
constexpr std::array<ull,10> factorials {1, 1, 2, 6, 24, 120, 720, 5'040, 40'320, 362'880 };
std::vector<ull> digits {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void main_subfunc_1 () {
    ull copy {limit};
    std::string value;
    int8_t idx {8};

    // This allows values to repeat. Permutation doesn't allow that.
    // We need to use factorial that can remove elements.
    while (idx >= 0)
    {
        const size_t quotient = std::floor(copy/factorials[idx]);
        value +=  std::to_string(quotient);
        copy -=  factorials[idx]*quotient;
        idx--;
    }

    std::cout << "The millionth permutation is " << value << "\n";
}


//Something is wrong with this implementation.
void main_subfunc_2 () {
    ull copy {limit};
    auto copy_digi {digits};
    std::string value {};

    // Decrement the copy value, by the current factorial[idx], incrementing count in the body.
    for (size_t idx { factorials.size()-1 }; idx != 0; idx--) {
        auto count {0};

        // Break when factorial[idx] greater than copy value.
        while (factorials[idx] < copy) {
            count++; copy -= factorials[idx];
        }

        // Append count, and erase the same value from digits.
        value += std::to_string(copy_digi[count]);
        copy_digi.erase(std::remove(copy_digi.begin(), copy_digi.end(), copy_digi[count]), copy_digi.end());
    }
    // Cleanse and Repeat.

    std::cout << "The millionth permutation is " << value << "\n";
}

void main_subfunc_3 () {
    ull copy {limit};
    auto copy_digi {digits};
    std::string value {};
    bool flag = true;

    for (size_t idx {factorials.size()-1}; flag; idx--) {

        const size_t counter = copy/factorials[idx];
        copy %= factorials[idx];

        value += std::to_string(copy_digi[counter]);

        auto target = copy_digi[counter];
        if (auto it = std::find(copy_digi.begin(), copy_digi.end(), target); it != copy_digi.end())
            copy_digi.erase(it);

        if (idx == 0) flag = false;
    }
    std::cout << "The millionth permutation is " << value << "\n";
}

int main () {
    main_subfunc_3();
    return 0;
}