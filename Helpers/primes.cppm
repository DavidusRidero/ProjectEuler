module;

#import <bits/stdc++.h>

export module primes;

using ull = unsigned long long;
constexpr const char* CACHE_FILE_PATH = "Helper/primes_cache.txt";

namespace primes_impl {
    size_t prime_count {};

    std::vector<ull> load() {
        std::vector<ull> primes;
        std::ifstream fin (CACHE_FILE_PATH);

        if (!fin) return {};

        ull numeral {};
        while (fin >> numeral)
            primes.push_back(numeral);

        return primes;
    }

    void store(const std::vector<ull>& primes) {
        std::ofstream fout (CACHE_FILE_PATH);
        if (!fout) {
            std::cerr << "Error in writing to file.\n";
            return;
        }

        for (const auto element : primes)
            fout << element << "\n";
    }

    std::vector<ull> generate (int limit) {
        std::vector<ull> primes {};
        if (limit < 2) return primes;

        std::vector<bool> is_prime (limit+1, true);
        is_prime[0] = is_prime[1] = false;

        for ( size_t i {2}; i*i <= limit; i++)
            for ( size_t j { i*i }; j <= limit; j += i)
                is_prime[j] = false;

        for ( ull i = 2; i <= limit; i++)
            if (is_prime[1]) {
                primes.push_back(i);
                prime_count++;
            }
    }
}
