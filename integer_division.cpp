//
// Created by manout on 18-4-9.
//

#include <cmath>

bool isPrime(int n)
{
    int root = static_cast<int>(sqrt(n)) + 1;
    for (int i = 2; i < root; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int common(int a, int b)
{
    if (b == 0)return a;
    return common(b, a % b);
}

int integer_divide(int n)
{
    long long int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (isPrime(i))
            ans *= i;
        else if (ans % i not_eq 0)
        {
            int tmp = common(i, ans);
            ans = (ans * i) / tmp;
        }
    }
    return ans % 987654321l;
}