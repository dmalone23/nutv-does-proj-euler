#include <iostream>

bool is_prime(int x);

// ripped straight from the wikipedia article on primality testing:
// https://en.wikipedia.org/wiki/Primality_test#C,_C++,_C#_&_D
bool is_prime(int x)
{
    if (x == 2 || x == 3)
        return true;

    if (x <= 1 || x % 2 == 0 || x % 3 == 0)
        return false;

    for (int i = 5; i * i <= x; i += 6)
    {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    }

    return true;
}

int main()
{
    int current_number = 0;
    int prime_count = 0;

    while (prime_count < 10001)
    {
        current_number++;
        if (is_prime(current_number))
        {
            prime_count++;
        }
    }

    std::cout << current_number << "\n";
}