#include "primes.h"
#include <bits/stdc++.h>

constexpr const char* CACHE_FILE_PATH = "Helper/primes_cache.txt";

namespace {
    std::vector<int> load_cached_primes() {
        std::vector<int> primes;

        // TODO:
        // 1. Open CACHE_FILE_PATH using std::ifstream
        // 2. Check if the file opened successfully
        // 3. Read integers sequentially and push_back into primes

        return primes;
    }

    void save_primes_to_cache(const std::vector<int>& primes) {
        // TODO:
        // 1. Open CACHE_FILE_PATH using std::ofstream
        // 2. Loop through the vector and write each prime to the file
    }

    std::vector<int> generate_primes_up_to(int limit) {
        std::vector<int> primes;

        // TODO:
        // Implement your choice of prime generation (e.g., Sieve of Eratosthenes or Trial Division)

        return primes;
    }
}

std::vector<int> get_primes(int limit) {
    std::vector<int> cached = load_cached_primes();

    // TODO:
    // 1. Check if 'cached' is not empty AND its largest prime (cached.back()) is >= limit
    // 2. If it satisfies the limit, return the cached primes (or a subset up to the limit)
    // 3. If it doesn't, call generate_primes_up_to(limit), save them to cache, and return them

    return cached; // Placeholder
}