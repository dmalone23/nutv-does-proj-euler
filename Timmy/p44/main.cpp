#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int get_pentagon_number(int n) {
    return (n * ((3 * n) - 1)) / 2;
}

int find_in_vector(vector<int> v, int i) {
    vector<int>::iterator it = find(v.begin(), v.end(), i);
    if (it != v.end()) {
        return distance(v.begin(), it);
    }
    return -1;
}

void solve() {
    int i = 0;
    vector<int> pents;
    while (true) {
        int new_p = get_pentagon_number(i);
        for (int j = 0; j < i; j++) {
            int j_val = pents.at(j);
            int k_val = new_p - j_val;
            int k = find_in_vector(pents, k_val);
            if (k != -1 and k != j) {
                int sub = find_in_vector(pents, abs(j_val - k_val));
                if (sub != -1) {
                    cout << abs(j_val - k_val) << endl;
                    return;
                }
            }
        }
        cout << "P[" << i << "] = " << new_p << endl;
        pents.push_back(new_p);
        i++;
    }
}

int main(int argc, char** argv) {
    solve();
    return 0;
}