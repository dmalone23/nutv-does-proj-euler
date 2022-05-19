#include <iostream>
#include <vector>

int main() {
    //std::vector<int> nums;

    int sum = 0;

    for(int i = 1; i < 1000; ++i){
        if(i%3 ==0 || i%5==0){
            //nums.push_back(i);
            sum = sum + i;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}