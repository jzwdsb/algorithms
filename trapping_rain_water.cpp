shi小于高度//
// Created by manout on 17-3-28.
//

#include "common_use.h"

/*
 *      Given n non-negative integers representing ab elevation map where width of each bar is 1,
 *  compute how much water it is able to trap after raining.
 *  分析：
 *      第一种方法，对每个柱子，找到它左边和右边的最高的柱子，所以这个柱子所能存储的水为　max(left, right) - height
 *      然后对每个柱子求和
 */

int trap(const vector<int>& A)
{
    const int n = A.size();
    vector<int> max_left(n, 0);
    vector<int> max_right(n, 0);
    for (int i = 1; i < n; ++i)
    {
        max_left[i] = max(max_left[i - 1], A[i - 1]);
        max_right[n - i - 1] = max(max_right[n - i], A[n - i]);
    }

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int capacity = max(max_left[i], max_right[i]);
        //如果容量小于高度，说明该柱子是所有柱子中最高的
        if (capacity > A[i])
        {
            sum += capacity - A[i];
        }
    }
    return sum;
}


