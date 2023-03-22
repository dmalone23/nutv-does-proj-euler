#include <iostream>
#include <vector>

using namespace std;

vector<int> GetFactors(int n) {
    vector<int> factors;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
        }
    }
    return factors;
}

int SumOfFactors(int n) {
    vector<int> factors = GetFactors(n);
    int sum = 0;
    for (int i = 0; i < factors.size(); ++i) {
        sum = sum + factors.at(i);
    }
    return sum;
}


bool CheckIfAmicable(int n) {
    int nd = SumOfFactors(n);
    int b = SumOfFactors(nd);
    return (b == n) && (n != nd);
}


int main(int argc, char** argv) {
    int sum = 0;
    for (int i = 1; i < 10000; ++i) {
        if (CheckIfAmicable(i)) {
            sum = sum + i;
            //cout << i << " is an amicable number." << endl;
        }
    }
    cout << "Sum of amicable nums under 10000 is " << sum << endl;
    return 0;
}