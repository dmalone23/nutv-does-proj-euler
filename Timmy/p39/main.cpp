#include <iostream>
#include <vector>
#include <string>
#include <string>
#include <bitset>
#include <math.h>
#include <tuple>
using namespace std;

void print3Tuple(tuple<int, int, int> t) {
    cout << "{" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << "}" << endl;
}

void printListOfTuples(vector<tuple<int, int, int>> ts) {
    for (int i = 0; i < ts.size(); i++) {
        print3Tuple(ts[i]);
    }
}

vector<tuple<int, int>> get_2_digit_sum(int sum) {
    vector<tuple<int, int>> sums;
    int i = 1;
    while (sum - i >= i) {
        int a = sum - i;
        sums.push_back(make_tuple(a, i));
        i++;
    }
    return sums;
}

vector<tuple<int, int, int>> get_3_digit_sum(int sum) {
    vector<tuple<int, int, int>> sums;
    int i = 2;
    while (i < sum) {
        int c = sum - i;
        vector<tuple<int, int>> sums2 = get_2_digit_sum(i);
        for (int t = 0; t < sums2.size(); t++) {
            int a = get<0>(sums2[t]);
            int b = get<1>(sums2[t]);
            if (pow(c,2) == pow(a,2) + pow(b,2)) {
                sums.push_back(make_tuple(c, a, b));
            }           
        }
        i++;
    }
    return sums;
}

void solve() {
    int max = 0;
    int p = 0;
    for (int i = 1; i <= 1000; i++) {
        int tris = get_3_digit_sum(i).size();
        if (tris > max) {
            max = tris;
            p = i;
        }
    }
    cout << p << ": " << max << endl;
}

int main(int argc, char** argv) {
    solve();
    return 0;
}