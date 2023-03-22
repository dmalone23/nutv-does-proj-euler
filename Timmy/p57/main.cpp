#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Frac{
    public:
        long num;
        long den;
        Frac(long n, long d) {
            num = n;
            den = d;
            simplify();
        }
        Frac add_one() {
            Frac new_f = Frac(num + den, den);
            new_f.simplify();
            return new_f;
        }
        Frac flip() {
            Frac new_f = Frac(den, num);
            new_f.simplify();
            return new_f;
        }
        void print() {
            cout << to_string(num) + "/" + to_string(den);
        }
        bool top_heavy() {
            int top = to_string(num).length();
            // cout << top << endl;
            int bottom = to_string(den).length();
            // cout << bottom << endl;
            return top > bottom;
        }
        void simplify() {
            // for (int i = den; i > 1; i--) {
            //     if (den % i == 0 && num % i == 0) {
            //         den = den / i;
            //         num = num / i;
            //     }
            // }
        }
};

Frac find_x(Frac prev) {
    long num_add = 2 * prev.den;
    Frac new_f = Frac(prev.num + num_add, prev.den);
    return new_f.flip();
}


int main(int argc, char** argv) {
    Frac prev_x = Frac(1,2);
    int top = 0;
    for (int i = 2; i <= 1000; i++) {
        prev_x = find_x(prev_x);
        cout << "y" + to_string(i) + " = ";
        prev_x.add_one().print();
        cout << endl;
        if (prev_x.add_one().top_heavy()) {
            // cout << "y" + to_string(i) + " is top heavy" << endl;
            top++;
            cout << to_string(top) + " have more digits in the numerator then denominator." << endl;
        }
    }
    return 0;
}