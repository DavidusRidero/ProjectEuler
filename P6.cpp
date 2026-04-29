#include <bits/stdc++.h>

//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

long sum_of_squares(const int n) {
    return (n*(n+1)*(2*n+1))/6;
}

long square_of_sums(const int n) {
    long ret = n*(n+1)*0.5;
    return ret*ret;
}


int main() {
    int input;
    std::cout << "Number: ";
    std::cin >> input;

    auto suos = sum_of_squares(input);
    auto sqos = square_of_sums(input);

    std::cout << "Square of Sums: " << sqos << "\n";
    std::cout << "Sum of Squares: " << suos << "\n";

    std::cout << "Solution: \t" << sqos-suos << "\n";

    return 0;
}