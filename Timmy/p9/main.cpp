#include <iostream>
#include <cmath>

int main(int argc, char** argv) {
    for (int a = 1; a < 1000; ++a) {
        for (int b = a + 1; b < 1000; ++b) {
            int as = pow(a, 2);
            int bs = pow(b, 2);
            int cs = as+bs;
            double maybeC = sqrt(cs);
            if (floor(maybeC) == ceil(maybeC)){
                int c = maybeC;
                if (c % 1 == 0 && c != a && c != b) {
                if (a + b + c == 1000) {
                    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
                    int product = a*b*c;
                    std::cout << "abc = " << product << std::endl;
                    return 0;
                }
            }
            }
            
        }
    }
    return 1;
}