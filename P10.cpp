#include <bits/stdc++.h>
//What is the 10,001st prime number?

std::vector<unsigned int> Primes;

void check(unsigned int n) {
    for (auto prime: Primes)
        if (n%prime == 0)
            return;

    Primes.push_back(n);
}

void print_primes() {
    for (auto prime:Primes)
        std::cout << prime << " ";
    std::cout << "\n";
}

int main() {
    unsigned int limit = 2000000;

    Primes.push_back(2);
    unsigned int counter = 3;

    while (Primes.back() <= limit)
        check(counter++);

    std::cout << "Biggest Prime less than " << limit << ": " << Primes.back() << std::endl;

    return 1;
}