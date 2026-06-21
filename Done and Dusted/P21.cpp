#include <bits/stdc++.h>

// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a != b,
// then a and b are an amicable pair and each of a and b are called amicable numbers.
// One example is 220 and 284.
// Evaluate the sum of all the amicable numbers under 10,000.

std::map<int,int> prime_factorize (unsigned value) {
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

unsigned sopd (const unsigned value ) {
    return theta_1_of(prime_factorize(value))-value;
}

void solve () {
    std::unordered_map<unsigned,unsigned> num_sum;
    std::set<std::pair<unsigned,unsigned>> ampairs;
    unsigned limit {30'000};

    while (limit>1) {
        num_sum.insert(std::make_pair(limit,sopd(limit)));
        limit--;
    }

    for (const auto& [num,sum]: num_sum) {
        // std::cout << "Number: " << std::setw(4) << num << "\t | \tSum of Proper Divisors: " << std::setw(4) << sum << "\n";
        if (num != sum and (num_sum[num] == sum) and (num_sum[sum] == num)) {
            auto max = std::max(num,sum);
            auto min = std::min(num,sum);
            ampairs.insert(std::make_pair(min, max));
        }
    }

    std::cout << "\nAmicable pairs found (if any): \n";
    unsigned answer {0};
    for (const auto & [one,other]: ampairs){
        std::cout << one << " " << other << "\n";
        answer += one + other;
    }

    std::cout << "Answer: " << answer << "\n";
}

void fancy (const unsigned value) {
    std::cout << "Sum of Divisors of " << value << " : " << sopd(value) << "\n";
}

int main() {
    // fancy(220); fancy(284);
    // fancy(1184); fancy(1210);
    // fancy(2620); fancy(2924);
    // fancy(5020); fancy(5564);

    solve();
    return 0;
}