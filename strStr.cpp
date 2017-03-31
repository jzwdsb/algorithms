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


