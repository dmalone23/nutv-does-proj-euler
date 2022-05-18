#include <iostream>
#include <string>

bool isPalindrome(int n){
    std::string str = std::to_string(n);
    int len = str.length();
    int f = 0;
    int b = len - 1;
    while (f <= b && f < len && b >= 0){
        if(str[f] != str[b]) {
            return false;
        }
        f = f + 1;
        b = b - 1;
    }
    return true;
}



int main(){
    int max = -1;
    for (int i = 999; i > 99; --i)  {
        for (int j = 999; j > 99; --j) {
            int n = i * j;
            if (isPalindrome(n)) {
                if (n > max) {
                    max = n;
                }
            }
        }
    }
    std::cout << max << std::endl;
    return 0;
}