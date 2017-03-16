//
// Created by manout on 17-3-13.
//

#include "common_use.h"

/*
 *      Given a string containing just the characters '(' and ')', find the length of the longest
 * valid (well-formed) parentheses substring.
 *      for "(()",the longest parentheses substring is "()", which has length = 1;
 *      Another example is ")()())", where the longest valid parentheses substring is "()()",which
 * has length = 4;
 */

int longest_valid_parentheses(const string &s)
{
    int max_len = 0
    int last = -1;                  //最后一次出现 ）的位置
    stack<int> lefts;               //记录没有匹配的 （ 的序号

    for (int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '(') {
            lefts.push(i);
        }else {
            if (lefts.empty())
            {
                //如果此时栈空，则表示这是个不能匹配的 ），记录其位置，他不能处于最长匹配序列中
                //之后的长度要以最后一个last的值来确定其长度
                last  = i;
            }else
            {
                //栈中存在未匹配的左括号
                lefts.pop();
                //无论栈是否空，都要求出当前位置到最后一个未匹配的 （ 或 ）的距离
                if (lefts.empty())
                {
                    //如果此时栈空，那么此时的最长匹配长度就是 i 到 最后一个未匹配的 ） 位置
                    max_len = max(max_len, i - last);
                }else
                {
                    //栈不空则要求出当前位置 i 到 最后一个未被匹配的 （ 位置
                    max_len = max(max_len, i - lefts.top());
                }
            }
        }
    }
    return max_len;
}
