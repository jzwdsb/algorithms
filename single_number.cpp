//
// Created by manout on 17-3-30.
//


/*
 *      Given an array of integer, every element appears twice except for one。
 *      Find the single one.
 *      分析：用异或，不仅能处理，还能处理所有偶数次情况。
 */
#include "common_use.h"


int single_number(const vector<int> & nums)
{
    int ret = 0;
    for(auto i : nums)
    {
        ret ^= i;
    }
    return ret;

}
