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
    unsigned long number = 600851475143;
    int largest_prime_factor = 0;

    for (int i = 5; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            if (is_prime(i))
            {
                if (i >= largest_prime_factor)
                {
                    largest_prime_factor = i;
                }
            }
        }
    }

    std::cout << largest_prime_factor << "\n";
}