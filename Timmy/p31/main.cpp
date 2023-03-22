#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <string>
using namespace std;

vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};

int findCombos(int n, int max) {
    int combos = 0;
    for (int i = 0; i < coins.size(); i++) {
        int coin = coins.at(i);
        if (coin <= max && coin <= n) {
            if (coin == n) {
                combos += 1;
            }
            else {
                combos += findCombos(n - coin, coin);
            }
        }
    }
    return combos;
}

int main(int argc, char** argv) {
    cout << findCombos(200,200) << endl;
    return 0;
}