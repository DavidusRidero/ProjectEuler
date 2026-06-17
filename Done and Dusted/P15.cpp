#include <bits/stdc++.h>
using ull = unsigned long long;

int main() {
    // Compute C(40,20) = (21*22*...*40) / 20!
    // Do division as we go to avoid overflow
    ull result = 1;
    for (int i = 0; i < 20; i++) {
        result *= (40 - i);   // multiply 40, 39, 38... 21
        result /= (i + 1);    // divide by 1, 2, 3... 20
    }
    std::cout << result << "\n";  // 137846528640
    return 0;
}