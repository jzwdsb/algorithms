//
// Created by manout on 17-4-5.
//
#include "common_use.h"

/*
 *      Implement atoi to convert a string to an integer.
 */



int my_atoi(const string& str)
{
    int num = 0;
    int sign = 1;
    const auto n = str.length();
    int i = 0;
    while(str[i] == ' ' and i < n)++i;
    if(str[i] ==  '+') sign = 1;
    else if(str[i] == '-') sign = -1;
    for ( ;i < n; ++i)
    {
        if( '0' > str[i] or str[i] > '9')
            break;
        if(num > INT32_MAX / 10 or num < INT32_MIN / 10 or
                (num == INT32_MAX / 10 and (str[i] - 0) > INT32_MAX % 10))
            return sign == 1 ? INT32_MAX : INT32_MIN;
        num = num * 10 + str[i] - '0';
    }
    return num * sign;
}