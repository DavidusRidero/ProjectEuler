#include <bits/stdc++.h>

// How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

enum Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, SUNDAY, DAY_COUNT };
enum Month { January, February, March, April, May, June, July, August, September, October, November, December, MONTH_COUNT };

Day cD = Tuesday;
Month cM = January;
int year = 1901;

unsigned int solution = 0;
unsigned leap = 1;

unsigned int february_offset() {
    if (leap != 4) {
        leap++; return 0;
    }
    leap = 1; return 1;
}

unsigned int offset (const Month month) {
    switch (month) {
        case February: return february_offset(); break;
        case April:
        case June:
        case September:
        case November:
            return 2; break;
        default:
            return 3; break;
    }
}

void increment_month () {
    // using enum Day;
    // using enum Month;

    unsigned int value = offset(cM);

    if (cM == December) { year++; std::cout << "\n";}


    cD = static_cast<Day> ((cD+value) % Day::DAY_COUNT);
    cM = static_cast<Month> ((cM+1) % Month::MONTH_COUNT);
}

bool is_first_sunday () {
    // using enum Day;

    bool sunday = false;

    if (cD == Day::SUNDAY) {
        solution++;
        sunday = true;
    }
    increment_month();
    return sunday;
}


// enum Month { January, February, March, April, May, June, July, August, September, October, November, December, MONTH_COUNT };
std::string getMonth (const Month month) {
    switch (month) {
        case January: return "January";
        case February: return "February";
        case March: return "March";
        case April: return "April";
        case May: return "May";
        case June: return "June";
        case July: return "July";
        case August: return "August";
        case September: return "September";
        case October: return "October";
        case November: return "November";
        case December: return "December";

        default: return {};
    }
}

// enum Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday, DAY_COUNT };
std::string getDay (const Day day) {
    switch (day) {
        case Monday: return "Monday";
        case Tuesday: return "Tuesday";
        case Wednesday: return "Wednesday";
        case Thursday: return "Thursday";
        case Friday: return "Friday";
        case Saturday: return "Saturday";
        case SUNDAY: return "SUNDAY";

        default: return {};
    }
}

int main () {
    const int years = 100;
    int loop = years * 12;

    while (loop--) {
        std::cout << "1st of " <<  std::setw(9) << getMonth(static_cast<Month>(cM)) << ", " << year << " is: " << getDay(cD);
        if (is_first_sunday()) {}
        std::cout << "\n";
    }

    std::cout << "Solution: " << solution << "\n";
}

//Fuck Yeah Baby.
//First Try.