#include <bits/stdc++.h>

//Find the sum of all the primes below two million.

using ull = unsigned long long;

ull solution (int limit) {
    ull primes {};
    if (limit < 2) return primes;

    std::vector<bool> is_prime (limit+1, true);
    is_prime[0] = is_prime[1] = false;

    for ( size_t i {2}; i*i <= limit; i++)
        for ( size_t j { i*i }; j <= limit; j += i)
            is_prime[j] = false;

    for ( ull i = 2; i <= limit; i++)
        if (is_prime[i])
            primes += i;

    return primes;
}

int main () {
    int limit = 2'000'000;
    // int limit= 10;

    std::cout << "Sum of Primes below " << limit << " is " << solution(limit) << ".\n";

    return 0;
}