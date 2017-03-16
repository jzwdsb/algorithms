//
// Created by manout on 17-3-14.
//

#include "common_use.h"

/*
 *      Implement next permutation, which rearranges numbers into the lexicographically next greater permutation
 * of numbers.
 *      If such arrangement is not possible, it must be rearrange it as the lowest possible order(ie, sorted in
 * ascending order);
 *      the replacement must be in-place, do not allocate extra memory.
 *
 *  分析：
 *      1：从右向左找到第一个不符合递增的元素，称为划分位置
 *      2：从右向左找到第一个大于划分元素的元素，称为交换位置
 *      3：将交换位置和划分位置的元素互换
 *      4：将划分位置右边的元素全部翻转
 *
 */

template<typename Bidit>
bool next_permutation_(Bidit, Bidit))

void next_permutation(vector<int> &nums)
{
    next_permutation_(nums.begin(), nums.end());
}

template <typename Bidit>
bool next_permutation_(Bidit first, last)
{

    const auto rfirst = reverse_iterator<Bidit> (last);
    const auto rlast = reverse_iterator<Bidit> (first);

    auto piot = prev(rfirst);
    //找到第一个不符合递增顺序的元素
    while (piot not_eq rlast and *piot >= *prev(piot))
    {
            ++piot;
    }
    //如果是最后一个，则表示该序列完全逆序，将其翻转后返回false
    if (piot == rlast)
    {
        reverse(rfirst, rlast);
        return false;
    }

    //这里使用的是lamda表达式，原书上是使用bind1st将less转化成一元算子
    auto exchge = find(rfirst,piot, [piot](Bidit it){return *it > *piot;});
    swap(*piot, exchge);
    reverse(rfirst, piot);
    return true;
}
