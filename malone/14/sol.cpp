#include <iostream>

long collatz_iter_count(unsigned long x);

long collatz_iter_count(unsigned long x)
{
    unsigned long iter_count = 1;

    while (x > 1)
    {
        if (x % 2 == 0)
        {
            x /= 2;
        }
        else
        {
            x = 3*x + 1;
        }
        iter_count++;
    }

    return iter_count;
}

int main()
{
    unsigned long max_iter_count = 1;
    unsigned long max_iter_starting_num = 1;

    for (unsigned long i = 1; i < 1000000; i++)
    {
        if (collatz_iter_count(i) >= max_iter_count)
        {
            std::cout << "i: " << std::to_string(i) << ", count: " << std::to_string(collatz_iter_count(i)) << "\n";
            max_iter_count = collatz_iter_count(i);
            max_iter_starting_num = i;
        }
    }

    std::cout << std::to_string(max_iter_starting_num) << "\n";
}