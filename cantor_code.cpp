//
// Created by manout on 17-3-16.
//

#include "common_use.h"

/*
 * 康托展开的实现
 * 康托展开是一个特殊的哈希函数，康托展开得到的值为这个序列在这个序列的全排序中的第几大排序
 * 原理：
 *      康托展开的公式为 X = a[n] * (n-1)! + a[n-1] * (n-2)! 。。。。。 + a[1] * 0!
 *      其中 a[n] 表示 a[n] 是在当前未出现的元素中排第几，从 0 开始
 *
 */




int get_index(vecotr<int>&, int);
int fact(int );

int cantor_expansion(vector<int> &nums)
{
    int ret = 0;
    int sz = nums.size();
    for (int i = 0; i < nums.size(); ++i)
    {
        ret += get_index(nums, i) * fact(sz - i -1);
    }
    return ret;
}


//返回这个元素在当前未出现的元素中排第几
int get_index(vecotr<int> &nums, int pos)
{
    int count = 0;
    for(int i = pos + 1; i < nums.size(); ++i)
    {
        if (nums[i] > nums[pos])
        {
            ++count;
        }
    }
    return count;
}


int fact(int fac)
{
    int result;
    for (int i = 1; i <= fac; ++i)
    {
        result *= i;
    }
    return result;
}

