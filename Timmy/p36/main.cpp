#include <iostream>
#include <vector>
#include <string>
#include <string>
#include <bitset>
using namespace std;

string remove_starting_zeros(string str) {
    if (str.at(0) == '0') {
        return remove_starting_zeros(str.substr(1, str.size()-1));
    }
    return str;
}

string to_binary(int n) {
    string full_binary = bitset<20>(n).to_string();
    return remove_starting_zeros(full_binary);
}

bool is_pal(string n) {
    int start = 0;
    int end = n.size() - 1;
    while (start < end) {
        if (n.at(start) != n.at(end)) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}



void solve() {
    int sum = 0;
    for (int i = 1; i < 1000000; i++) {
        string bin = to_binary(i);
        if (is_pal(bin) && is_pal(to_string(i))) {
            sum += i;
        }
    }
    cout << sum << endl;
}

int main(int argc, char** argv) { 
    solve();
    return 0;
}