//
// Created by manout on 17-3-8.
//
#include "common_use.h"
#include <limits.h>

/*
 *      Given an array S of integers, find three integers in S such that
 * the sum is closest to an given number target. return the three integers.
 * You may assume that each input would have exactly one solution.
 *      For example, given array S = {-1, 2, 1, -4}, and target = 1.
 *      The sum that is closest to the target is 2 (-1 + 2 + 1 = 2).
 *
 *  分析：
 *      和上一道找三个数等于 0 的思想基本相同
 *      先排序，然后左右夹逼， 时间复杂度 O(n2)
 */

//Leetcode, 3sum closest
//先排序，然后左右夹逼，时间复杂度O(n2)，空间复杂度O(1)
int three_sum_closest(vector<int> &nums, int target){
    int result = 0;
    int min_gap = INT_MAX;
    sort(nums.begin(), nums.end());

    for (auto front = nums.begin(); front != prev(nums.end(), 2); ++front) {
        auto mid = next(front);
        auto tail = prev(nums.end());
        while(mid < tail){
            const int sum = *front + *mid + *tail;
            const int gap = abs(target - sum);
            if (min_gap > gap){
                result = sum;
                min_gap = gap;
                if(min_gap == 0)return result;
            }
            //如果和小于目标值，将中间的迭代器向后移动一位
            if (sum < target){
                ++mid;
            }
            //如果和大于目标值，将指向最大的数的迭代器向前移动一位
            else {
                --tail;
            }
        }
    }
    return result;
}