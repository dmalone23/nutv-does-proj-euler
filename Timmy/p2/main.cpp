#include <iostream>

int main(){
    int a = 1;
    int b = 1;
    int sum = 0;

    while (b < 4000000){
        if (b % 2 == 0) {
            sum = sum + b;
        }
        int next = a + b;

        a = b;
        b = next;
    }

    std::cout << sum <<std::endl;
    return 0;
}