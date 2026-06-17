#include <bits/stdc++.h>
#include "../Helpers/integers.cppm"

std::ifstream& operator>> (std::ifstream& fin, integer& number) {
    std::string raw_input;

    if (fin >> raw_input)
        number = integer(raw_input);

    return fin;
}

void subfunction () {
    const std::string number1 = "82616570773948327592232845941706525094512000000008";
    const std::string number2 = "99999999999999999999999999999999999999999999999999";

    integer n1 (number1);
    integer n2 (number2);

    std::cout << "Original: \n"<< number1 << "\n";
    n1.print();
    std::cout << "Original: \n"<< number2 << "\n";
    n2.print();

    n1 = n1 + n2;
    std::cout << "Sum: \n"; n1.print();
}

int main () {
    std::ifstream fin ("P13_Input.txt");

    integer number {}, temp;
    while ( fin >> temp )
        number += temp;

    std::cout << "Solution: ";
    number.print();
    // The question was for first 10. But gave the entire string.
    // So no first try this time.
    return 0;
}