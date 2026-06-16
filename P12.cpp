#include <bits/stdc++.h>

using ull = unsigned long long;

ull triangle (int n) {
    return static_cast<int> (n*(n+1)*0.5);
}

unsigned int divisors (ull number) {
    if (number == 1) return 1;

    unsigned int n_divs = 1;

    for (size_t i {2}; i*i <= number; i++)
        if (number % i == 0) {
            unsigned int count = 0;
            while (number % i == 0) {
                count++;
                number /= i;
            }
            n_divs *= (count+1);
        }

    if (number > 1)
        n_divs *= 2;

    return n_divs;
}

int main () {

    int i = 10;
    while (divisors(triangle(i++)) < 500) {}
    i--;

    std::cout << i << "th triangle number (" << triangle(i) << ") has " << divisors(triangle(i)) << " divisors.\n";
    std::cout << i-1 << "th triangle number (" << triangle(i-1) << ") has " << divisors(triangle(i-1)) << " divisors.\n";
    return 0;
}