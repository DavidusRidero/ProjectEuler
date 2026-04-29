#include <bits/stdc++.h>
//What is the 10,001st prime number?

std::vector<int> Primes;

void check(int n) {
    for (int prime: Primes)
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
    int size;
    std::cout << "\nEnter position:";
    std::cin >> size;

    Primes.push_back(2);
    int counter = 3;
    while (Primes.size() != size)
        check(counter++);

    std::cout << "Prime at position " << size << ": " << Primes.back() << "\n\n";

    int wish;
    std::cout << "Wish to see all primes? (1 or 0): ";
    std::cin >> wish;

    if (wish)
        print_primes();

    return 0;
}