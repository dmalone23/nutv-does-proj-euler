#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

vector<string> getNext(vector<string> v) {
    
    vector<string> perm;
    if (v.size() == 1) {
        vector<string> s;
        s.push_back(v.at(0));
        return s;
    }
    else {
        for (int i = 0; i < v.size(); ++i) {
            string first_char = v.at(0);
            vector<string> remaining;
            for (int j = 0; j < v.size(); ++j) {
                if (j != i) {
                    remaining.push_back(v[j]);
                }
            }
            vector<string> next = getNext(remaining);
            for (int s = 0; s < next.size(); ++s) {
                perm.push_back(first_char.append(next.at(s)));
            }
            if (perm.size() >= 1000000) {
                return perm;
            }
            if(v.size() == 10) {
                cout << "i: " << remaining.size() << endl;
            }
        }
    }
    return perm;
}

int factorial(int n) {
    int prod = n;
    for (int i = 1; i < n; ++i) {
        prod *= i;
    }
    return prod;
}

vector<string> removeFromList(string remove, vector<string> nums) {
    vector<string> newVec;
    for(int i = 0; i < nums.size(); i++) {
        if (nums[i] != remove) {
            newVec.push_back(nums[i]);
        }
    }
    return newVec;
}

int next(int n, string prefix, vector<string> nums) {
    if (nums.size() == 1) {
        cout << "The " << n << " is " << prefix << nums[0] << endl;
        //sleep(1);
        return n+1;
    }
    for (int i = 0; i < nums.size(); i++) {
        string current = nums[i];
        vector<string> suffix = removeFromList(current, nums);
        n = next(n, prefix + current, suffix);
        if (n > 1000000) {
            return n;
        }
    }
    return n;
}


int main(int argc, char** argv) {
    vector<string> nums;
    nums.push_back("0");
    nums.push_back("1");
    nums.push_back("2");
    nums.push_back("3");
    nums.push_back("4");
    nums.push_back("5");
    nums.push_back("6");
    nums.push_back("7");
    nums.push_back("8");
    nums.push_back("9");

    // vector<string> perms = getNext(nums);
    // for(int i = 0; i < 1000000; ++i) {
    //     cout << "The " << i << "th perm is " << perms.at(i) << endl;
    // }

    next(1, "", nums);
    return 0;
}