#include <iostream>

int main()
{
    /*
     * using euclid's formula below
     * for any 2 numbers m and n, m > n:
     * - a = m^2 - n^2
     * - b = 2mn
     * - c = m^2 + n^2
     */

    int a, b, c = 0;

    for (int n = 1; n <= 99; n++)
    {
        for (int m = 2; m <= 100; m++)
        {
            a = (m * m) - (n * n);
            b = 2 * m * n;
            c = (m * m) + (n * n);

            if (a + b + c == 1000)
            {
                break;
            }
        }
    }

    std::cout << std::to_string(a * b * c) << "\n";
}