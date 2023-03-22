#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> factorials = {1};

void fillFactorial() {
    for (int i = 1; i < 10; i++) {
        factorials.push_back(factorials.at(i-1) * i);
    }
}

void printVec(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << ", ";
    }
    cout << endl;
}

bool equalsFactorialSum(int n) {
    string nStr = to_string(n);
    int sum = 0;
    for (int i = 0; i < nStr.size(); i++) {
        int digit = nStr.at(i) - '0';
        sum += factorials.at(digit);
    }
    return sum == n;
}

int sumOfAllFactorials(int n) {
    int sum = 0;
    for (int i = 10; i < n; i++) {
        if (equalsFactorialSum(i)) {
            sum += i;
        }
    }
    return sum;
}

int main(int argc, char** argv) {
    fillFactorial();
    cout << sumOfAllFactorials(100000000) << endl;
    return 0;
}