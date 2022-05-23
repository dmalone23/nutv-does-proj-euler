#include <iostream>

long divisor_count(int x);

long divisor_count(int x)
{
    long divisor_count = 0;
    long half_x = (long) (x / 2);

    for (int i = 1; i <= half_x; i += 1)
    {
        if (x % i == 0)
        {
            divisor_count++;
        }
    }

    return divisor_count;
}

int main()
{
    long current_triangle = 1;
    long triangle_divisor_count = 0;

    for (int i = 1000; i < 50000; i++)
    {
        current_triangle += i;
        triangle_divisor_count = divisor_count(i);
        if (triangle_divisor_count > 500)
        {
            std::cout << std::to_string(i) << "\n";
            break;
        }
    }

    return 0;
}