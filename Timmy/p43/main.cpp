#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> generate_permutations(vector<int> v) {
    vector<vector<int>> perms;
    if (v.size() == 1) {
        perms.push_back(v);
        return perms;
    }
    for (int i = 0; i < v.size(); i++) {
        vector<int> new_v = v;
        int tail = new_v.at(i);
        new_v.erase(new_v.begin()+i);
        vector<vector<int>> ps = generate_permutations(new_v);
        for (auto &p : ps) {
            p.push_back(tail);
            perms.push_back(p);
        }
    }
    return perms;
}

void print_vector_int(vector<int> v) {
    for (auto &n : v) {
        cout << to_string(n);
    }
    cout << endl;
}

void print_vector(vector<vector<int>> v) {
    for (auto &n : v) {
        print_vector_int(n);
    }
}

int vector_to_int(vector<int> v) {
    int i = 0;
    i = i + (v.at(0) * 100);
    i = i + (v.at(1) * 10);
    i = i + (v.at(2) * 1);
    return i;
}

bool check_vector_prop(vector<int> v) {
    vector<int> two = {v.begin() + 0, v.begin() + 3};
    vector<int> three = {v.begin() + 0, v.begin() + 3};
    vector<int> five = {v.begin() + 0, v.begin() + 3};
    vector<int> seven = {v.begin() + 0, v.begin() + 3};
    vector<int> eleven = {v.begin() + 0, v.begin() + 3};
    vector<int> thirteen = {v.begin() + 0, v.begin() + 3};
    vector<int> seventeen = {v.begin() + 0, v.begin() + 3};
    vector<int> divisible = {2,3,5,7,11,13,17};
    for (int i = 1; i < 8; i++) {
        vector<int> check = {v.begin() + i, v.begin() + (i+3)};
        int num = vector_to_int(check);
        int d = divisible.at(i-1);
        if (num % d != 0) {
            //cout << to_string(num) << " / " << to_string(d) << " != 0" << endl;
            return false;
        }
        else {
            //cout << to_string(num) << " / " << to_string(d) << " == 0" << endl;
        }
    }
    return true;
}

long vector_to_long(vector<int> v) {
    long l = 0;
    for(auto &d : v) {
        l = (l * 10) + d;
    }
    return l;
}

int main(int argc, char** argv) {
    vector<vector<int>> perms = generate_permutations({1,2,3,4,5,6,7,8,9,0});
    vector<vector<int>> valid;
    for (auto &p : perms) {
        if (check_vector_prop(p)) {
            valid.push_back(p);
        }
    }
    long sum = 0;
    for (auto &p : valid) {
        long l = vector_to_long(p);
        sum = sum + l;
    }
    cout << sum << endl;
    return 0;
}