#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> getDigits(int n) {
    vector<int> digits;
    string numStr = to_string(n);
    for (int i = 0; i < numStr.size(); i++) {
        int digit = numStr.at(i) - '0';
        digits.push_back(digit);
    }
    return digits;
}

bool isPandigital(int a, int b, int prod) {
    vector<int> digits;
    vector<int> aDigits = getDigits(a);
    vector<int> bDigits = getDigits(b);
    vector<int> prodDigits = getDigits(prod);
    for (int i = 0; i < aDigits.size(); i++) {
        int d = aDigits.at(i);
        if (find(digits.begin(), digits.end(), d) != digits.end()) {
            return false;
        }
        else {
            digits.push_back(d);
        }
    }
    for (int i = 0; i < bDigits.size(); i++) {
        int d = bDigits.at(i);
        if (find(digits.begin(), digits.end(), d) != digits.end()) {
            return false;
        }
        else {
            digits.push_back(d);
        }
    }
    for (int i = 0; i < prodDigits.size(); i++) {
        int d = prodDigits.at(i);
        if (find(digits.begin(), digits.end(), d) != digits.end()) {
            return false;
        }
        else {
            digits.push_back(d);
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (find(digits.begin(), digits.end(), i) == digits.end()) {
            return false;
        }
    }

    return find(digits.begin(), digits.end(), 0) == digits.end();
}

int solve() {
    vector<int> prods;
    int sum = 0;
    int a  = 1;
    while (true) {
        int aDigits = to_string(a).size();
        if (aDigits > 4) {
            break;
        }
        int b = 1;
        while (true) {
            int bDigits = to_string(b).size();
            int prod = a * b;
            int prodDigits = to_string(prod).size();
            int digitsSum = aDigits + bDigits + prodDigits;
            if (digitsSum > 9) {
                break;
            }
            else if (digitsSum == 9)
            {
                if (isPandigital(a, b, prod)) {
                    if (find(prods.begin(), prods.end(), prod) == prods.end()) {
                        prods.push_back(prod);
                        sum += prod;
                    }
                }
            }
            b++;
        }
        a++;
    }
    return sum;
}

int main(int argc, char** argv) {
    cout << solve() << endl;
    return 0;
}