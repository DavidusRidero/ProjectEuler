#include<bits/stdc++.h>
typedef unsigned long long ull;

bool is_palindrome(const ull n) {
    const std::string s1 = std::to_string(n);
    std::string s2 = s1;
    std::reverse(s2.begin(),s2.end());

    return s1==s2;
}

int main() {
    ull largest = 0;

    int i=999,j=999;
    for (i=999; i>99; i--)
        for (j=999; j>99; j--)
            if (is_palindrome(i*j))
                largest = std::max(largest, ull(i*j));

    std::cout << "Largest Palindrome: " << largest;
    return 9;
}