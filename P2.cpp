#include <bits/stdc++.h>
typedef unsigned long long ull;
using Mat = std::array<ull, 4>;

//First try baby.

Mat multiply(const Mat& A, const Mat& B) {
    return {
        A[0]*B[0] + A[1]*B[2],
        A[0]*B[1] + A[1]*B[3],
        A[2]*B[0] + A[3]*B[2],
        A[2]*B[1] + A[3]*B[3]
    };
}

long long fib(int n) {
    n = n+2;
    Mat result = {1,0,0,1};
    Mat base   = {1,1,1,0};

    while (n > 0) {
        if (n & 1) result = multiply(result, base);
        base = multiply(base, base);
        n >>= 1;
    }

    return result[1];
}

int main() {
    ull limit = 4000000;
    ull sum = 0;

    for ( size_t i = 0; ;i++) {
        ull value = fib(i);
        if (value > limit) break;

        if (value&1) continue;

        sum+=value;
        std::cout << "Fibonacci[" << i << "] is " << value << "\n";
    }

    std::cout << "\nSum of even-Fibs : " << sum << "\n";
    return 1;
}