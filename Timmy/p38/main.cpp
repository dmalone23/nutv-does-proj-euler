#include <iostream>
#include <vector>
#include <string>
#include <string>
#include <bitset>
#include <math.h>
using namespace std;

bool useAllNine(string num) {
    for (int i = 1; i < 10; i++) {
        char c = '0' + i;
        if (num.find(c) == string::npos) {
            return false;
        }
    }
    return true;
}

int getPandigital(int num) {
    string conProd = "";
    int n = 0;
    while(conProd.length() < 9) {
        int prod = num * (n + 1);
        conProd += to_string(prod);
        n++;
    }
    if (conProd.length() != 9 || n == 1 || !useAllNine(conProd)) {
        return 0;
    }
    else {
        return stoi(conProd);
    }
}

int solve(){
    int max = 0;
    for (int i = 1; i < 10000; i++) {
        int p = getPandigital(i);
        if (p > max) {
            max = p;
        }
    }
    return max;
}

int main(int argc, char** argv) {
    cout << solve() << endl;
    return 0;
}