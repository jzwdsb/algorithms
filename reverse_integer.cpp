//
// Created by manout on 17-8-12.
//

#include <iostream>
#include <sstream>
#include <string>
#include <climits>

using std::string;
using std::stringstream;
using std::cout;


int reverse(int x)
{
    int flag;
    long num;
    stringstream ss;
    string num_str, re_str;
    flag = x >= 0 ? 1 : -1;
    ss << x;
    ss >> num_str;
    re_str.assign(num_str.rbegin(), num_str.rend());
    ss.clear();
    ss << re_str;
    ss >> num;
    if (num > INT_MAX)
    {
        return 0;
    }
    return static_cast<int>(num * flag);
}


