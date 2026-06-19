#include <bits/stdc++.h>

// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a != b,
// then a and b are an amicable pair and each of a and b are called amicable numbers.
// One example is 220 and 284.
// Evaluate the sum of all the amicable numbers under 10,000.

std::map<int,int> prime_factorize (int value) {
    std::map<int,int> primes_powers;

    for (auto i {2}; i*i <= value; i++)
        while (value % i == 0) {
            primes_powers[i]++;
            value /= i;
        }

    if (value > 1)
        primes_powers[value]++;

    return primes_powers;
}

unsigned int theta_x_of (unsigned int x, const std::map<int,int>& primes_powers) {
    assert (x!=0);
    unsigned int sum = 1;

    for (auto & [prime, power]: primes_powers)
        sum *= static_cast<unsigned int>((std::pow(prime,(power+1)*x)-1)/(std::pow(prime,x)-1));

    return sum;
}

unsigned int theta_1_of ( const std::map<int,int>& primes_powers ) {
    auto sum = 1;

    for (auto & [prime, power]: primes_powers)
        sum *= (std::pow(prime, power+1) - 1)/(prime -1);

    return sum;
}

void print_primes (const std::map<int,int>& primes_powers) {
    for (auto [primes, power]: primes_powers)
        std::cout << "Power of " << primes << " : " << power << "\n";
}

int main() {
    constexpr auto value = 220;
    const auto prime_power = prime_factorize(value);
    std::cout << "Sum of Divisors of " << value << " : " << theta_1_of(prime_power)-value << "\n";

    return 0;
}