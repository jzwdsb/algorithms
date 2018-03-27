//
// Created by manout on 18-3-27.
//

#include <iostream>
#include <string>

using namespace std;

static  int check(int num)
{
    string str;
    for (int i = 1 ; i <= num; ++i)
    {
        str += to_string(i);
    }
    int sum = 0;
    for (char i : str)
    {
        sum += i - '0';
    }
    return sum % 3 == 0;
}

int divide_three(int left, int right)
{
    int ans = 0;
    for (int i = left; i <= right; ++i)
    {
        if (check(i))
            ++ans;
    }
    return ans;
}

