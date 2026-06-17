#include <bits/stdc++.h>

using ull = unsigned long long;

ull even (ull value) {
    return value/2;
}

ull odd (ull value) {
    return (3*value)+1;
}

std::pair<ull,ull> collatz_length (ull value) {
    ull length {1};
    ull copy = value;

    while (true) {
        if (value%2 == 0) //Even
            value = even(value);
        else
            value = odd(value);
        length++;
        if (value==1) break;
    }
    return std::make_pair(length,copy);
}

int main() {
    ull value = 1'000'000;
    std::set<std::pair<ull,ull>,std::greater<>> lengths;


    while (true) {
        lengths.insert(collatz_length(value));
        value--;
        if (value == 1) break;
    }

    //You fucking idiot
    //They are asking for value which produces the longest length.
    //You are giving them the length.
    std::cout << "Value: " << lengths.begin()->second << " has collatz length of " << lengths.begin()->first;

    return 0;
}