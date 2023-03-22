#include <iostream>
#include <vector>
#include <string>
#include <string>
#include <bitset>
#include <math.h>
using namespace std;

string gen_string(int n) {
    int i = 1;
    string s = "";
    while (s.size() <= n) {
        s += to_string(i);
        i += 1;
    }
    return s;
}

void solve() {
    string s = gen_string(1000000);
    int prod = 1;
    for (int i = 0; i < 7; i++) {
        int digit = pow(10, i);
        int atd = s.at(digit-1) - '0';
        prod *= atd;
    }
    cout << prod << endl;
}

void print_n_digits(string s, int n) {
    for (int i = 0; i < n; i++) {
        cout << s.at(i) << endl;
    }
}

int main(int argc, char** argv) {
    solve();
    return 0;
}