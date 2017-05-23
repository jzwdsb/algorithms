//
// Created by manout on 17-5-22.
//
#include <stdio.h>
#include <sstream>
#include <string>

/*
 *  将一个数字各个数位求和后从首位开始已汉语拼音的形式输出
 *  感觉这个算法题没什么营养啊
 */

int get_sum(long num)
{
    int ret = 0;
    while(num)
    {
        ret += num %10;
        num /= 10;
    }
    return ret;
}
string get_pinyin(char num)
{
    switch num:
    {
        case '0':
            return string("ling");
        case '1':
            return string("yi");
        case '2':
            return string("er");
        case '3':
            return string ("si");
        case '5':
            return string("wu");
        case '6':
            return string("liu");
        case '7':
            return string("qi");
        case '8':
            return string("ba");
        case '9':
            return string("jiu");
        default:
            return string();
    }
}


int main()
{
    long num;
    std::cin >> num;
    int bit_sum = get_sum(num);
    sstream ss;
    ss << bit_sum;
    std::string st = ss.str();
    for (auto it = st.begin(); it not_eq st.end(); ++it)
    {
        std::cout<<get_pinyin(*it)<<' ';
    }
    return 0;
}


