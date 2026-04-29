#include <bits/stdc++.h>

// What is the smallest positive number that is evenly divisible by all the numbers from 1 to 20?
// Hand solved it. but still.

std::map<int,int> Primes;

//We prime factorize from the upper threshold.
void prime_f(int n) {
    std::map<int,int> primes;
    for (int d = 2; d * d <= n; d++)
        while (n%d==0) {
            primes[d]++; n /=d;
        }
    if (n>1) primes[n]++;

    //We have the prime factorization of n here.
    //We compare the powers to existing map of prime and powers.
    //We keep the std::max of the original and the new input.

    for (auto [prime,power] : primes)
        Primes[prime] = std::max(Primes[prime],primes[prime]);

    //Original Primes must have been updated by now.
}


int main() {
    constexpr int threshold = 20;
    double solution = 1;
    for (int i = 2; i<=threshold; i++)
        prime_f(i);

    std::cout << threshold << "! is reduced to \n";
    for (auto [prime,power] : Primes) {
        std::cout << prime << "^" << Primes[prime] << "\n";
        solution *= std::pow(prime,power);
    }

    std::cout << "\nSolution is " << static_cast<unsigned int>(solution) << "\n";
}