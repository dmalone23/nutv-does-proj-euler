#include <iostream>
#include <math.h>
using namespace std;

int sumOfDiagonals(int s) {
    if (s == 1) {
        return 1;
    }
    int right = pow(s, 2);
    int n = s - 1;
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum = sum + (right - (n * i));
    }
    return sum;
}

int getTotalSum(int s) {
    int sum = 0;
    for (int i = s; s > 0; s = s - 2) {
        sum = sum + sumOfDiagonals(s);
    }
    return sum;
}

int main(int argc, char** argv) {
    cout << getTotalSum(1001) << endl;
    return 0; 
}