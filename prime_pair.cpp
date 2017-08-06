//
// Created by manout on 17-8-6.
//

#include <vector>
#include <math.h>

bool judge_prime(int num)
{
    int root;
    root = static_cast<int>(sqrt(num) + 1);

    for (int i = 0; i < root; ++i)
    {
        if(num % i not_eq 0)
            return false;
    }
    return true;
}

int count_prime_pair(int num)
{
    int count = 0;
    int prev = 1, next = 1;

    for (int i = 1; i <= num; ++i)
    {
        if  (judge_prime(i))
        {
            prev = next;
            next = i;
            if (prev not_eq next and next - prev == 2)
                ++count;
        }

    }
    return count;
}
