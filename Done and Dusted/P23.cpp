#include <bits/stdc++.h>

// Prime factorization, and Sum of Divisor implementation
// We use std::vector<std::pair<uint8_t,uint8_t>> for primes and powers.
// (Slow) Bring in an array of 25-50ish primes, for a faster factorization in the average case.
// We go with W3 Pritchard's wheel. Factorize with 2,3,5, then use the delta array to jump to next values.
//  + The array is aligned with 7, so start the loop with it.

using uint = size_t;
using ull = unsigned long long;
using decomp = std::vector<std::pair<uint,uint>>;

constexpr std::array<int,8> delta {4,2,4,2,4,6,2,6};

// Prime factorization of a given value.
// This one is slower than the W3 function.
decomp factorize (ull value)
{
    assert (value > 1);
    decomp primes_factors;

    {
        size_t power2 {0};
        while (value % 2 == 0) {
            power2++;
            value /= 2;
        }

        if (power2)
            primes_factors.emplace_back(2,power2);
    }


    for (ull prime {3}; prime*prime <= value; prime +=2) {
        uint power {0};

        while (value % prime == 0) {
            power++;
            value /= prime;
        }

        if (power)
            primes_factors.emplace_back(prime,power);
        }

    if (value > 1)
        primes_factors.emplace_back(value,1);

    return primes_factors;
}

decomp factorize_w3 (ull value) {
    assert(value > 1);

    decomp primes_factors;
    constexpr std::array basis {2,3,5};

    for (int base: basis) {
        size_t power {0};
        while (value % base == 0) {
            power++;
            value /= base;
        }

        // Insert if divisible.
        if (power)
            primes_factors.emplace_back(base,power);
    }

    // Completely divisible by 2, 3 and 5.
    if (value == 1)
        return primes_factors;

    // Wheel comes in.
    ull prime {7};
    size_t idx = 0;

    while (prime*prime <= value) {
        size_t power {0};

        while (value % prime == 0) {
            power++;
            value /= prime;
        }

        // Insert if divisible.
        if (power)
            primes_factors.emplace_back(prime,power);

        prime += delta[idx];
        idx = (idx+1) % 8;
    }

    if (value > 1)
        primes_factors.emplace_back(value,1);

    return primes_factors;
}

ull n_divs (const ull value, const bool proper = true) {
    // Number of divisors is given by product of 1-incremented powers.
    uint number {1};

    // for (const auto &power: factorize_w3(value) | std::views::values)
    //     number *= power+1;

    for (const auto& [_,power] : factorize_w3(value))
        number *= power+1;

    // The number itself isn't counted as a proper divisor.
    return proper ? number - 1 : number;
}

ull safe_pow(ull base, ull expo) {
    if (base == 1 or expo == 0) return 1;
    if (base == 0) return 0;

    ull power {1};

    // Mistake caught by Deepseek. 1 -> 0.
    while (expo > 0) {
        if (expo & 0b1U) {
            if (power > __UINT64_MAX__ / base) {
                std::cerr << "Overflow during exponentiation.\n"; exit(1);
            }
            power *= base;
        }
        expo >>= 1;

        // Mistake caught by Deepseek. Overflow can happen here too.
        if (expo > 0) {
            if (base > __UINT64_MAX__ / base) {
                std::cerr << "Overflow during exponentiation.\n"; exit(1);
            }
            base *= base;
        }
    }
    return power;
}

ull s_divs (const ull value, const bool proper = true) {
    // Sum of divisors is given by the "Divisor Function" wikipedia page.
    ull sum {1};

    // std::pow is a trap, cause double has lesser precision than ull.
    for (const auto& [prime,power]: factorize_w3(value))
        sum *= ((safe_pow(prime, power+1) - 1)/(prime - 1));

    // The number itself isn't counted in the sum of proper divisors.
    return proper ? sum - value : sum;
}

enum class Perfection { Abundant, Perfect, Deficient };
Perfection perfection (const ull value) {
    const ull sum_of_proper_divisors = s_divs(value);

    if (value < sum_of_proper_divisors)
        return Perfection::Abundant;
    else if (value == sum_of_proper_divisors)
        return Perfection::Perfect;
    else
        return Perfection::Deficient;
}

// Manual checks.
void sub_main_1 () {
    // constexpr ull num = 11;
    // std::cout << num << " is " << perfection(num) << ".\n";
}

// Number of Abundants.
void sub_main_2 () {
    size_t counter {0};
    // ull limit {28'123};
    ull limit {100};

    std::cout << "\nNumber of abundants under " << limit;

    while (limit>1) {
        // auto perfect = perfection(limit);
        // std::cout << limit << " is " << perfect << ".\n";
        if (perfection(limit) == Perfection::Abundant) counter++;
        limit--;
    }

    std::cout << " is " << counter << "\n";
}


// GIVEN UP. Will use brute-force in sub_main_4().
void sub_main_3 () {
    // ull limit {28'123};
    // ull limit = 100;
    // ull counter = 2;
    //
    // std::set<ull> true_abundant {};
    // std::set<ull> false_abundant {};
    // std::set<ull> solution_space {};
    //
    // while (counter < limit) {
    //     // False abundant check i.e. a multiple of true abundant.
    //     if ( false_abundant.find(counter) != false_abundant.end()) {}
    //
    //     // True Abundant check. If yes, populate false_abundant with multiples.
    //     else if (perfection(counter) == "Abundant") {
    //         true_abundant.insert(counter);
    //         for (ull mult {2}; mult*counter <= limit; mult++)
    //             false_abundant.insert(mult*counter);
    //     }
    //
    //     // Check for candidacy
    //     else {
    //
    //     }
    //     counter++;
    // }
}

constexpr ull limit {28'123};
void sub_main_4 () {
    std::vector<ull> abundants;
    // Assume all are unreachable, we strike off the reachable ones.
    std::bitset<limit+1> unreachable; unreachable.set();

    // TODO: Find all abundant numbers under 28,123. There are 6965 of such. Populate them into abundants.
    for (ull counter = 2; counter <= limit; counter++)
        if (perfection(counter) == Perfection::Abundant)
            abundants.emplace_back(counter);

    // Sanity check. Size has to be 6965.
    // std::cout << "Size of abundants: " << abundants.size() << "\n";

    // TODO: Mark all multiples of abundants as reachable.
    for (const ull abundant: abundants)
        for (size_t mult {2}; mult*abundant <= limit; mult++)
            unreachable[mult*abundant] = false;

    // TODO: Generate all possible sums of 2 abundants, and mark them as reachable.
    for (size_t first = 0; first < abundants.size(); first++)
        for (size_t second = first + 1; second < abundants.size(); second++) {
            const size_t target = abundants[first] + abundants[second];
            if (target > limit)
                break;
            unreachable[target] = false;
        }

    // TODO: Sum all the rest.
    ull sum {0};
    for (size_t idx {0}; idx < unreachable.size(); idx++)
        if (unreachable[idx])
            sum += idx;

    std::cout << "Sum of all numbers that cannot be represented as sum of 2 abundant numbers: " << sum << "\n";
}

int main() {
    sub_main_4();

    return 0;
}