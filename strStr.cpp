//
// Created by manout on 17-3-31.
//

#include "common_use.h"


int strStr(const string& text, const string& pattern)
{
    if(pattern.empty())return 0;

    const auto  N = pattern.length();
    const auto  len = text.length() - N - 1;
    for (int i = 0; i < len; ++i) {
        int j = i;
        int k = 0;
        while(j < len and k < N and text[j] == pattern[k])
        {
            ++j;
            ++k;
        }
        if(k == N)
            return i;
    }
    return -1;
}

//对pattern构造部分匹配表
//整个pattern 到当前i之前（不包含i）的部分字符串中有多长相同的前缀后缀
//next数组只是当匹配失败时，pattern应当跳到那一位置
void compute_prefix(const string& pattern, vector<int>& next)
{
    int j = -1;
    const auto len = pattern.length();
    for (int i = 0; i < len; ++i) {
        //自身匹配表的指示器的回退
        while(j > -1 and pattern[j] == pattern[j + 1]) j = next[j];
        if(pattern[i] == pattern[j + 1]) ++j;
        next[i] = j;
    }
}


int kmp(const string& text, const string& pattern)
{
    int i;
    int j = -1;
    const auto n = text.length();
    const auto m = pattern.length();
    //空文本，空模式，返回０
    if(n == 0 and m == 0)return 0;
    //文本不空，模式为空
    if(m == 0)return 0;
    vector<int> next(m);
    compute_prefix(pattern, next);

    for(i = 0; i < n; ++i)
    {
        while(j > -1 and pattern[j + 1] not_eq pattern[i])j = next[j];
        if(j == m - 1)
            //j表示匹配的模式字符串位置，到达尾部便已匹配成功
            //返回向前回退j 的位置
            return i - j;
    }
    return -1;

}

