#pragma once
#include <vector>

std::vector<int> get_primes(int limit);

std::vector<int> load_cached_primes();
void save_primes_to_cache(const std::vector<int>& primes);
std::vector<int> generate_primes_up_to(int limit);