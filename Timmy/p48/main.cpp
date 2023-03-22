#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

unsigned long long int pow(int b, int e) {
    unsigned long long int prod = 1;
    for (int i = 0; i < e; i++) {
        prod *= b;
        prod %= 10000000000;
    }
    cout << b << "^" << e << " = " << prod << endl;
    return prod;
}

unsigned long long int sumOfPow(int n) {
    unsigned long long int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(i, i);
    }
    return sum;
}

int main(int argc, char** argv) {
    cout << sumOfPow(1000) << endl;
    return 0;
}