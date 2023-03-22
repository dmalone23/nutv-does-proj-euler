#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimesBelow(int n) {
    vector<int> primes;
    for (int i = 2; i < n; i++) {
        bool isPrime = true;
        for (int p = 0; p < primes.size(); p++) {
            if (i % primes.at(p) == 0) {
                isPrime = false;
                break;
            }
            else if (primes.at(p) > i/2)
            {
                break;
            }
            
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }  
    return primes;
}

void printVec(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << ", ";
    }
    cout << endl;
}

int vecSum(vector<int> vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec.at(i);
    }
    return sum;
}

void solve(int n) {
    vector<int> primes = getPrimesBelow(n);
    cout << "GOT PRIMES" << endl;
    cout << "There are " << primes.size() << " primes." << endl;
    cout << "The Last Prime is " << primes.at(primes.size()-1) << endl;
    //printVec(primes);
    int maxSeqLen = 0;
    int maxSum = 0;
    int start = 0;
    map<int, map<int, int>> sums;
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            if (i == j) {
                sums[i][j] = primes.at(j);
            }
            else {
                sums[i][j] = sums[i][j-1] + primes.at(j);
            }
            if (find(primes.begin(), primes.end(), sums[i][j]) != primes.end()) {
                if ((j-i) + 1 > maxSeqLen) {
                    maxSeqLen = (j-i) + 1;
                    maxSum = sums[i][j];
                    start = i;
                }
            }
        }
    }
    // for (int i = 0; i < primes.size() - 1; i++) {

    //     for (int j = 0; j < primes.size() - i; j++) {
    //         int len = primes.size() - (i+j);
    //         if (len <= maxSeqLen) {
    //             break;
    //         }
    //         vector<int> subvec = {primes.begin() + i, primes.end() - j};
    //         int sum = vecSum(subvec);
    //         if (find(primes.begin(), primes.end(), sum) != primes.end()) {
    //             maxSeqLen = len;
    //             maxSum = sum;
    //             start = primes.at(i);
    //             cout << "The longest sum starting at p[" << i << "] = " << primes.at(i) << " is " << len << " long with a sum of " << sum << endl;
    //         }
    //     }
    // }
    cout << start << endl;
    cout << maxSeqLen << ", " << maxSum << endl;
}

map<int, map<int, int>> getPrimes(int max) {
    map<int, map<int, int>> primeSums;
    vector<int> primes;
    int last_prime = 0;
    for (int i = 2; i < max; i++) {
        bool prime = true;
        for (auto &p : primes) {
            if (i % p == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            primes.push_back(i);
            primeSums[i][1] = i;
            if(last_prime > 0) {
                for (int n = 2; n < primes.size(); n++) {
                    primeSums[i][n] = primeSums[last_prime][n-1] + i;
                }
            }
            last_prime = i;
        }
    }
    return primeSums;
}

void printVector(vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        cout << ", ";
    }
    cout << "]" << endl;
}

vector<int> getPrimesBelow2(int n) {
    vector<int> primes;
    vector<int> sums;
    int max_seq = 0;
    for (int i = 2; i < n; i++) {
        bool isPrime = true;
        for (int p = 0; p < primes.size(); p++) {
            if (i % primes.at(p) == 0) {
                isPrime = false;
                break;
            }
            else if (primes.at(p) > i/2)
            {
                break;
            }
            
        }
        if (isPrime) {
            primes.push_back(i);
            printVec(primes);
            sums.push_back(0);
            for (int s = 0; s < sums.size(); s++) {
                sums[s] = sums[s] + i;
                cout << "sums[" + to_string(s) + "] = " + to_string(sums[s]) << endl;
                vector<int>::iterator it = find(primes.begin(), primes.end(), sums[s]);
                if (it != primes.end()) {
                    cout << sums[s] << endl;
                    int seq_len = primes.size() - s;
                    cout << seq_len <<endl;
                    if (seq_len > max_seq) {
                        max_seq = seq_len;
                    }
                }
            }
        }
    }  
    cout << "MAX SEQ LENGTH: " + to_string(max_seq) << endl;
    return primes;
}

void solve2(int max) {
    vector<int> primes = getPrimesBelow(max);
    cout << "FOUND ALL PRIMES" << endl;
    vector<int> sums;
    int max_seq_len = 0;
    for (int i = 0; i < primes.size(); i++) {
        int p = primes[i];
        sums.push_back(0);
        for (int s = 0; s < sums.size(); s++) {
            sums[s] = sums[s] + p;
            int seq_len = i - s + 1;
            if (seq_len > max_seq_len && sums[s] < max) {
                vector<int>::iterator it = find(primes.begin(), primes.end(), sums[s]);
                if (it != primes.end()) {
                    max_seq_len = seq_len;
                }
            }
        }
    }
    cout << max_seq_len << endl;
}

int main(int argc, char** argv) {
    //solve(100);
    solve2(1000000);
    //getPrimesBelow2(100);
    return 0;
}