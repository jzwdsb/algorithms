//
// Created by manout on 18-2-24.
//

#include <string>
#include <algorithm>
#include <iostream>

static bool check_is(int num)
{
    std::string num_s = std::to_string(num);
    std::reverse(num_s.begin(), num_s.end());
    int num_r = std::stoi(num_s);
    return num - num_r == 27;
}

int guess_age()
{
    int count_ = 0;
    for (int i = 27; i < 100; ++i)
    {
        if (check_is(i))
        {
            ++count_;
        }
    }
    return count_;
}
