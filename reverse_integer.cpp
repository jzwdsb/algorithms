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
    // 当上一次的字符流使用完毕时，会留下一个 eofbit 的error state
    // 所以当再次使用该字符流时，应该调用clear清空错误码，否则输入流会不进行操作退出

    ss.clear();
    ss << re_str;
    ss >> num;
    if (num > INT_MAX)
    {
        return 0;
    }
    return static_cast<int>(num * flag);
}

