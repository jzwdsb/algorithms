//
// Created by manout on 18-2-24.
//

#include <string>
#include <iostream>

static bool check_is(int num)
{
    int num_r = (num % 10) * 10 + num / 10;
    return num  - num_r == 27;
}

int guess_age()
{
    int count_ = 0;
    for (int i = 27; i < 100; ++i)
    {
        if (check_is(i))
        {
            std::cout << i << std::endl;
            ++count_;
        }
    }
    return count_;
}
