#include <iostream>
#include <math.h>
using namespace std;

int b(long n) {
    int i = 0;
    long max = 0;
    while (true) {
        long nextMultiple = pow(2, i);
        if (n % nextMultiple == 0) {
            max = nextMultiple;
        }
        i++;
        if (nextMultiple >= n) {
            return max;
        }
    }
}

long A(long x) {
    if (x == 0) {
        return 1;
    }
    else if(x % 2 == 0) {
        long n = x/2;
        return (3 * A(n)) + (5 * A((2*n) - b(n)));
    }
    else {
        long n = (x - 1) / 2;
        return A(n);
    }
}

int H(long t, long r) {
    return A(pow(pow(2, t) + 1, r));
}

int main(int argc, char** argv) {
    cout << H(pow(10,14)+31,62) << endl;
    return 0; 
}