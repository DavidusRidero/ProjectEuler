#include<bits/stdc++.h>
typedef unsigned long long ull;

void prime_factorize(ull n) {
    std::vector<int> prime_factors;
    ull divisor = 2;

    while (divisor*divisor <= n) {
        while (n%divisor == 0) {
            prime_factors.emplace_back(divisor);
            n/=divisor;
        }
        divisor++;
    }

    if (n>1)
        prime_factors.emplace_back(n);

    std::cout << "Largest Prime Factor: " << *prime_factors.rbegin() << "\n\n";

    for (auto i:prime_factors)
        std::cout << i << "\n";
}

int main() {
    ull n = 90809;
    prime_factorize(n);

    return 1;
}

