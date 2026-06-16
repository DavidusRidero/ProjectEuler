#include "primes.h"
#include <bits/stdc++.h>

constexpr const char* CACHE_FILE_PATH = "Helper/primes_cache.txt";
using ull = unsigned long long;

namespace {
    size_t count {};

    std::vector<ull> load_cached_primes() {
        std::vector<ull> primes;

        // TODO:
        // 1. Open CACHE_FILE_PATH using std::ifstream
        std::ifstream fin(CACHE_FILE_PATH);
        // 2. Check if the file opened successfully
        if (!fin) {
            std::cerr << "Error: couldnt open file.\n";
            exit(1);
        }
        // 3. Read integers sequentially and push_back into primes
        ull numeral {};
        while ( fin >> numeral )
            primes.push_back(numeral);

        fin.close();
        return primes;
    }

    void save_primes_to_cache(const std::vector<ull>& primes) {
        // TODO:
        // 1. Open CACHE_FILE_PATH using std::ofstream
        std::ofstream fout (CACHE_FILE_PATH);
        if (!fout) {
            std::cerr << "Error: File output failure.\n";
            exit(1);
        }

        // 2. Loop through the vector and write each prime to the file
        for (auto element: primes)
            fout << element << "\n";

        fout.close();
    }

    std::vector<ull> generate_primes_up_to(int limit) {
        std::vector<ull> primes;

        if ( limit < 2 )
            return primes;

        // TODO:
        // Implement your choice of prime generation (e.g., Sieve of Eratosthenes or Trial Division)
        std::vector<bool> is_prime (limit+1, true);
        is_prime[0] = false;
        is_prime[1] = false;

        for (size_t i {2}; i*i <= limit; i++)
            if (is_prime.at(i))
                for (size_t j {i*i}; j <= limit; j +=i )
                    is_prime[j] = false;

        for (ull i {2}; i <= limit; i++)
            if (is_prime[i]) {
                primes.push_back(i);
                count++;
            }

        return primes;
    }
}

std::vector<ull> get_primes(int limit) {
    std::vector<ull> cached = load_cached_primes();

    // TODO:
    // 1. Check if 'cached' is not empty AND its largest prime (cached.back()) is >= limit
    if ( !cached.empty() and cached.back() >= limit )
        // 2. If it satisfies the limit, return the cached primes (or a subset up to the limit)
        return {cached.begin(), cached.begin()+limit};

    // 3. If it doesn't, call generate_primes_up_to(limit), save them to cache, and return them
    cached = generate_primes_up_to(limit);
    save_primes_to_cache(cached);

    return cached;
}
