//
// Created by manout on 18-3-23.
//

#include <cmath>

static int count = 0;

inline
int mypow(int n)
{
    return static_cast<int>(std::pow(2, n));
}

static void coin(int n, int k, int sum)
{
    int pow = mypow(k);
    if (sum + pow < n)
    {
        coin(n, k + 1, sum + pow);
        coin(n, k, sum + pow);
        return ;
    }else if (sum + pow == n)
    {
        ++count;
        return ;
    }
}

int count_coin(int n)
{
    coin(n, 0, 0);
    return count;
}

