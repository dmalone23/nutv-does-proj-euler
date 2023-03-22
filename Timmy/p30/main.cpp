#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <string>
using namespace std;

int getUpperLimit() {
    int i = 0;
    int n = 0;
    while (true) {
        n += 9 * pow(10, i);
        if (n > (i+1) * pow(9, 5)) {
            break;
        }
        i++;
    }
    return (i+1) * pow(9, 5);
}

bool isSum(int n) {
    string numStr = to_string(n);
    int sum = 0;
    for (int i = 0; i < numStr.size(); i++) {
        int digit = numStr.at(i) - '0';
        sum += pow(digit, 5);
    }
    return sum == n;
}

int solve() {
    int upperLimit =  getUpperLimit();
    int sum = 0;
    for (int i = 10; i < upperLimit; i++) {
        if (isSum(i)) {
            sum += i;
        }
    }
    return sum;
}

int main(int argc, char** argv) {
    cout << solve() << endl;
    return 0;
}