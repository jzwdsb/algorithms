//
// Created by manout on 18-3-23.
//

#include <cmath>

static int count = 0;

__always_inline
int mypow(int n)
{
    return static_cast<int>(std::pow(2, n));
}

static int coin(int n, int k, int sum)
{
    int pow = mypow(k);
    if (sum + pow == n)
    {
        ++count;
    }
    if (sum + pow < n)
    {
        coin(n, k + 1, sum);
        coin(n, k + 1, sum + pow);
        if (sum + 2 * pow < n)
        {
            coin(n, k + 1, sum + 2 * pow);
        }
    }

}

int count_coin(int n)
{
    count = 0;
    coin(n, 0, 0);
    return count;
}

