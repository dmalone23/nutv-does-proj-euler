#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long factorial(int max, int min) {
    long prod = 1;
    for (int i = max; i > min; i--) {
        prod = prod * i;
    }
    return prod;
}

long factorial(int max) {
    return factorial(max, 1);
}

long solve_nom(int n, int r) {
    int max = 0;
    int min = 0;
    if (r > n - r) {
        max = r;
        min = n - r;
    }
    else {
        max = n - r;
        min = r;
    }
    long top = factorial(n, max);
    return top / factorial(min);
}

int main(int argc, char** argv) {
    int over_mil = 0;
    for (int n = 1; n <= 100; n++) {
        for (int r = 1; r <= n; r++) {
            long combos = solve_nom(n, r);
            if (combos > 1000000) {
                cout << "(" << to_string(n) << ", " << to_string(r) << ") is " << to_string(combos) << endl;
                over_mil++;
            }
        }
    }
    cout << over_mil << endl;
    return 0;
}