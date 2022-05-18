#include <iostream>
#include <cmath>
#include <string>

int sumOfSquares(int max){
    int sum = 0;
    for (int i = 1; i <= max; ++i){
        sum = sum + pow(i, 2);
    }
    return sum;
}

int squareOfSums(int max){
    int sum = 0;
    for (int i = 1; i <= max; ++i){
        sum = sum + i;
    }
    return pow(sum, 2);
}

int diff(int max) {
    return squareOfSums(max) - sumOfSquares(max);
}


int main(int argc, char** argv){
    int val = -1;
    if (argc == 2){
        val = atoi(argv[1]);
    }
    else {
        val = 100;
    }
    std::cout << diff(val) << std::endl;
    return 0;
}