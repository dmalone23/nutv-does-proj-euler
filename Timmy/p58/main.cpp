#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_prime(int n) {
    for (int i = 2; i < n/2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


int main(int argc, char** argv) {
    int sides = 3;
    int primes = 3;
    int i = 0;
    while (true) {
        sides = sides + 2;
        int max = sides * sides;
        for (int i = 0; i < 4; i++) {
            int new_n = max - (((sides-1)*i));
            //cout << new_n << endl;
            if (is_prime(new_n)) {
                //cout << new_n << endl;
                primes = primes + 1;
            }
        }
        int diags = ((sides - 1) * 2) + 1;
        float percent = 100.0 * ((float)primes/(float)diags);
        //cout << percent << endl;
        cout << to_string(sides) + " has " + to_string(primes) + " primes. " + to_string(percent) + "\% primes." << endl;
        if (percent < 10) {
            break;
        }
        i++;
    }
    return 0;
}