#include <iostream>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

void printVectorInt(vector<int> u) {
    cout << "[";
    for (int i = 0; i < u.size(); i++) {
        cout << u[i] << ", ";
    }
    cout << "]" << endl;
}

void printListOfVectorInt(vector<vector<int>> us) {
    for (int i = 0; i < us.size(); i++) {
        printVectorInt(us[i]);
    }
}

int pi(int n) {
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 0; j < primes.size(); j++) {
            if (i % primes[j] == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
    return primes.size();
}

bool checkIfPrime(int n) {
    // if (n == 1) {
    //     return true;
    // }
    vector<int> primes;
    bool nPrime = false;
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 0; j < primes.size(); j++) {
            if (i % primes[j] == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
        if (i == n) {
            nPrime = isPrime;
        }
    }
    return nPrime;
}

int c(vector<int> u) {
    int count = 0;
    for (int i = 0; i < u.size(); i++) {
        if (checkIfPrime(u[i])) {
            count = count + 1;
        }
    }
    return count;
}

vector<vector<int>> generateUs(int u0) {
    vector<vector<int>> us;
    int n1 = pi(u0);
    if (n1 == 0) {
        return us;
    }
    vector<int> base = {u0, n1};
    us.push_back(base);
    vector<vector<int>> others = generateUs(n1);
    for (int i = 0; i < others.size(); i++) {
        vector<int> u = others[i];
        vector<int>::iterator it = u.begin();
        u.insert(it, u0);
        us.push_back(u);
    }
    return us;
}

map<int, int> pDetails(int n) {
    map<int, int> kSums;
    for (int i = 1; i <= n; i++) {
        vector<vector<int>> us = generateUs(i);
        for (int j = 0; j < us.size(); j++) {
            int k = c(us[j]);
            if (kSums.find(k) == kSums.end()) {
                kSums[k] = 1;
            }
            else {
                kSums[k] = kSums[k] + 1;
            }
        }
    }
    return kSums;
}

void printPDetails(map<int, int> m) {
    vector<int> key, value;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        key.push_back(it->first);
        value.push_back(it->second);
        cout << "m[" << it->first << "] = " << it->second << endl;
    }
}

int p(int n, int k) {
    return pDetails(n)[k];
}

int P(int n) {
    map<int, int> kSums = pDetails(n);
    vector<int> key, value;
    for (map<int, int>::iterator it = kSums.begin(); it != kSums.end(); ++it) {
        key.push_back(it->first);
        value.push_back(it->second);
    }
    int prod = 1;
    for (int i = 0; i < value.size(); i++) {
        prod = prod * value[i];
    }
    return prod;
}

int main(int argc, char** argv) {
    for (int i = 0; i <= 10; i++) {
        printListOfVectorInt(generateUs(i));
    }
    printPDetails(pDetails(10));
    cout << P(10) << endl;
    cout << p(10, 1) << endl;
    return 0; 
}