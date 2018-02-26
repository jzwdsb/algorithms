//
// Created by manout on 18-2-25.
//


#include <tar.h>
#include <algorithm>
#include <iostream>

__always_inline
int equation(int x, int y, int z)
{
    return x * x + y * y + z * z;
}

__always_inline
int min(int x, int y, int z)
{
    return std::min(std::min(x, y), std::min(y, z));
}

int solve_equation()
{
    for (int x = 0; x < 1000; ++x)
    {
        for (int y = 0; y < 1000; ++y)
        {
            for (int z = 0; z < 1000; ++z)
            {
                if (equation(x, y, z) == 1000)
                {
                    return min(x, y, z);
                }
            }
        }
    }
}