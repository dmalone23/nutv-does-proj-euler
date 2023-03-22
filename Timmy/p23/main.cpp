#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool isAbundant(int n) {
    int sumOfDiv = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sumOfDiv += i;
        }
    }
    return sumOfDiv > n;
}

vector<int> getAllAbundantNumberBelow(int n) {
    vector<int> abundant;
    for (int i = 1; i <= n; i++) {
        if (isAbundant(i)) {
            abundant.push_back(i);
        }
    }
    return abundant;
}

bool canSum(int n, vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > n) {
            break;
        }
        if (find(nums.begin(), nums.end(), n - nums[i]) != nums.end()) {
            return true;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    int max = 28123;
    int sum = 0;
    vector<int> abundant = getAllAbundantNumberBelow(max);
    cout << "GOT ABUNDANTS" << endl;
    for (int i = 1; i < max; i++) {
        if (!canSum(i, abundant)) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}