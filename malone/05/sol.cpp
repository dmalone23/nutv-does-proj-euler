#include <iostream>

bool is_divisible_by_first_20(int x);

bool is_divisible_by_first_20(int x)
{

    for (int i = 1; i <= 20; i += 1)
    {
        if (x % i != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    unsigned int current_number = 0;

    while (current_number < UINT_MAX)
    {
        current_number++;
        if (is_divisible_by_first_20(current_number))
        {
            break;
        }
    }

    std::cout << current_number << "\n";
}