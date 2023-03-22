#include <iostream>

bool is_prime(int x);

// once again ripped straight from the wikipedia article on primality testing:
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
    long prime_sum = 0; // thanks Timmy!

    for (int i = 1; i <= 2000000; i++)
    {
        if (is_prime(i))
        {
            prime_sum += i;
        }
    }

    std::cout << std::to_string(prime_sum) << "\n";

    return 0;
}