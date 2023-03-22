#include <iostream>
#include <math.h>
#include <map>
#include <vector>

using namespace std;

vector<int> getPrimesBelow(int n) {
    vector<int> primes;
    for (int i = 2; i <= n; i++){
        bool isPrime = true; 
        for (int p = 0; p < primes.size(); p++) {
            if (i % primes[p] == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            primes.push_back(i);
        }
    }
    return primes;
}

int primesOfQuad(int a, int b, vector<int> primes){
    int n = 0;
    while (true) {
        int quad = pow(n, 2) + (a * n) + b;       
    }
}

bool isPrime(int n, vector<int> primes) {
    if (n <= 1000) {
        for (int i = 0; i < primes.size(); i++) {
            if (n == primes[i]) {
                return true;
            }
            if (n % primes[i] == 0) {
                return false;
            }
        }
        return true;
    }
    else {
        vector<int> newPrimes = getPrimesBelow(n);
        if (newPrimes[newPrimes.size() - 1] == n) {
            return true;
        }
        else {
            return false;
        }
    }
}

void solve() {
    vector<int> primes = getPrimesBelow(1000);
    map<int, map<int, int>> counts;
    int max = -1;
    int maxA = -1;
    int maxB = -1;
    
    for (int a = -999; a <= 1000; a++) {
        for (int bi = 0; bi < primes.size(); bi++) {
            int b = primes[bi];
            int n = 0;
            int countPrimes = 0;
            while (true) {
                int quad = pow(n, 2) + (a * n) + b;
                //cout << "QUAD: " << quad << endl;
                if (isPrime(quad, primes)) {
                    countPrimes += 1;
                    n += 1;
                }
                else {
                    break;
                }
            }
            //cout << "n^2 + " << a << "*n + " << b << " creates " << countPrimes << "primes." << endl;
            if (countPrimes > max) {
                max = countPrimes;
                maxA = a;
                maxB = b;
            }
        }
    }

    cout << maxA << " * " << maxB << " = " << maxA*maxB << endl;
}

int main(int argc, char** argv) {
    solve();

    return 0;
}