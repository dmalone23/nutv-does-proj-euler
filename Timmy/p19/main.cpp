#include <iostream>
#include <vector>
#include <string>

int GetDayOfNextMonth(int day, int month, int year) {
    int add;
    int days = 31;
    switch (month) {
        case 0: //J
            break;
        case 1: //F
            if (year % 4 == 0) {
                days = 29;
                if (year % 100 == 0 && year % 400 != 0) {
                    days = 28;
                }
            }
            else {
                days = 28;
            }
            break;
        case 2: //M
            break;
        case 3: //A
            days = 30;
            break;
        case 4: //May
            break;
        case 5: //June
            days = 30;
            break;
        case 6: //July
            break;
        case 7: //A
            break;
        case 8: //S
            days = 30;
            break;
        case 9: //O
            break;
        case 10: //N
            days = 30;
            break;
        case 11: //D
            break;
    }
    day = (day + days) % 7;
    return day;
}


int main(int argc, char** argv) {
    int sum = 0;
    int day = 2;
    int month = 0;
    int year = 1901;
    while (year < 2001) {
        int nextDay = GetDayOfNextMonth(day, month, year);
        int nextMonth = (month + 1) % 12;
        int nextYear = year;
        if(nextMonth == 0) {
            nextYear = nextYear + 1;
        }

        //std::cout << "The " << nextMonth << " month of the year " << nextYear << " starts on the " << nextDay << " day of the week." << std::endl;
        if (nextDay == 0 && nextYear < 2001) {
            sum = sum + 1;
        }
        day = nextDay;
        month = nextMonth;
        year = nextYear;

    }
    std::cout << sum << " months start on Sundays." << std::endl;
    return 0;
}