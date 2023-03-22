#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

void printIntVec(vector<int> nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ", ";
    }
    cout << "]" << endl;
}

int longDiv(int den) {
    int num = 1;
    vector<int> sub;
    vector<int> seq;
    int i = 1;
    while (true) {
        // cout << "i = " << i << endl;
        i += 1;
        if (num < den) {
            num = num * 10;
            sub.push_back(num);
            seq.push_back(0);
            continue;
        }
        int times = num / den;
        num = num % den;
        num = num * 10;
        seq.push_back(times);
        if (num == 0) {
            // for (int i = 0; i < seq.size(); i++) {
            //     cout << seq[i] << endl;
            // }
            return 0;
        }
        vector<int>::iterator it;
        if (seq.size() > 0 && (it = find(sub.begin(), sub.end(), num)) != sub.end()) {
            
            int start = it-sub.begin();
            int length = seq.size() - (1+start);
            // cout << "length: " << length << endl;
            // printIntVec(seq);
            return length;
        }
        sub.push_back(num);
        // cout << "sub: ";
        // printIntVec(sub);
        // cout << "seq: ";
        // printIntVec(seq);
        //sleep(1);
        
    }
}

int main(int argc, char** argv) {
    int max = 0;
    int maxD = 0;
    for (int i = 1; i < 1000; i++) {
        int seq = longDiv(i);
        if (seq > max) {
            max = seq;
            maxD = i;
        }
    }
    cout << maxD << endl;
    
    return 0;
}