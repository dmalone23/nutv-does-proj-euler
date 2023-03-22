#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool checkIfValid(int a, int b) {
    int aTen = a / 10;
    int aOne = a % 10;
    int bTen = b / 10;
    int bOne = b % 10;
    float quotient = (float) a / (float) b;
    if (aTen == bTen) {
        float q = (float) aOne / (float) bOne;
        return q == quotient;
    }
    else if (aOne == bOne)
    {
        return false;
        float q = (float) aTen / (float) bTen;
        return q == quotient;
    }
    else if (aTen == bOne) 
    {
        float q = (float) aOne / (float) bTen;
        return q == quotient;
    }
    else if (aOne == bTen) 
    {
        float q = (float) aTen / (float) bOne;
        return q == quotient;
    }
    else {
        return false;
    }
}

vector<int> findFactors(int n) {
    vector<int> factors;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
        }
    }
    return factors;
}

int findGCF(int a, int b) {
    vector<int> aFactors = findFactors(a);
    vector<int> bFactors = findFactors(b);
    int max = 0;
    for (int i = 0; i < aFactors.size(); i++) {
        if (find(bFactors.begin(), bFactors.end(), aFactors.at(i)) != bFactors.end()) {
            if (aFactors.at(i) > max) {
                max = aFactors.at(i);
            }
        }
    }
    return max;
}

int findFracs() {
    int nProd = 1;
    int dProd = 1;
    for (int n = 10; n < 99; n++) {
        for (int d = n + 1; d < 100; d++) {
            if (checkIfValid(n, d)) {
                nProd *= n;
                dProd *= d;
            }
        }
    }
    int gcf = findGCF(nProd, dProd);
    return dProd / gcf;
}

int main(int argc, char** argv) {
    cout << findFracs() << endl;
    return 0;
}