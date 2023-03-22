#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

bool is_prime(int num) {
    for (int i = 2; i < num/2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> generate_permutations(vector<int> digits) {
    vector<int> perms;
    if (digits.size() == 1) {
        return digits;
    }
    for (int d = 0; d < digits.size(); d++) {
        vector<int> digits_copy = digits;
        int digit = digits.at(d) * pow(10, digits.size() - 1);
        digits_copy.erase(digits_copy.begin() + d);
        vector<int> new_perms = generate_permutations(digits_copy);
        for (int p = 0; p < new_perms.size(); p++) {
            int num = new_perms.at(p) + digit;
            vector<int>::iterator it = find(perms.begin(), perms.end(), num);
            if (it == perms.end()) {
                perms.push_back(num);
            }
        }
    }
    sort(perms.begin(), perms.end());
    return perms;
}

vector<int> generate_prime_permutations(vector<int> digits) {
    vector<int> perms = generate_permutations(digits);
    //cout << "PERMS: " + to_string(perms.size()) << endl;
    for (int pi = 0; pi < perms.size(); pi++) {
        int p = perms.at(pi);
        if (!is_prime(p) || p < 1000) {
            perms.erase(perms.begin()+pi);
            pi -= 1;
        }
    }
    //cout << "PRIME PERMS: " + to_string(perms.size()) << endl;
    return perms;
}

void print_vector_int(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums.at(i) << endl;
    }
}

bool find_seq(vector<int> nums) {
    if (nums.size() < 3) {
        return false;
    }
    for (int f = 0; f < nums.size() - 2; f++) {
        int first = nums.at(f);
        for (int s = f + 1; s < nums.size() - 1; s++) {
            int second = nums.at(s);
            int fs_diff = second - first;
            if (fs_diff == 3330) {
                for (int t = s + 1; t < nums.size(); t++) {
                    int third = nums.at(t);
                    int st_diff = third - second;
                    if (st_diff == 3330) {
                        //cout << "DIFF = " + to_string(st_diff) << endl;
                        cout << "SEQ = " + to_string(first) + " " + to_string(second) + " " + to_string(third) << endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void solve() {
    vector<vector<int>> combos;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                for(int l = 0; l < 10; l++) {
                    vector<int> digits = {i, j, k , l};
                    sort(digits.begin(), digits.end());
                    vector<vector<int>>::iterator it = find(combos.begin(), combos.end(), digits);
                    if (it == combos.end()) {
                        combos.push_back(digits);
                        find_seq(generate_prime_permutations(digits));
                    }
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    solve();
    return 0;
}