#include<bits/stdc++.h>

bool is_triplet (int a, int b, int c) {
    return (a*a + b*b == c*c);
}


int main () {
    int a,b,c;

    a = 247;
    b = 336;
    c = 1000-a-b;

    std::cout << a << " Squared: " << a*a << std::endl;
    std::cout << b << " Squared: " << b*b << std::endl;
    std::cout << std::endl;
    std::cout << "Squared sum: " << a*a+b*b << std::endl;
    std::cout << c << " Squared: " << c*c << std::endl;
    std::cout << std::endl;
    std::cout << "Difference: " << c*c-b*b-a*a<< std::endl;
    std::cout << std::endl;
    std::cout << "Is triplet: " << is_triplet(a,b,c) << std::endl;
    std::cout << "Sum: " << a+b+c;
    return 1;
}