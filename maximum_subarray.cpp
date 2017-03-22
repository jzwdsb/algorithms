//
// Created by manout on 17-3-22.
//

#include "common_use.h"

/*
 *      Find the contiguous sub_array within array(containing at least one number)which has the largest sum
 *
 *      分析：
 *          最大连续子序列的和
 *          当我们从头到尾遍历这个数组的时候，对于数组里的一个整数，它只有两种选择
 *          1：加入之前的sub_array
 *          2：自己另起一个sub_array
 *          如果之前的sub_array的和是大于0的，那么认为其对后续是有贡献的，我们选择加入之前的sub_array
 *          如果之前的sub_array的和是不大于0的，那么认为其对后续是没有或者负贡献的，我们选择另起一个sub_array
 *          设状态f[j]，表示以S[j]结尾的最大连续子序列的和，状态转移方程为
 *              f[j] = max{f[j - 1] + S[j], S[j]}，其中1 <= j <= n
 *              target = max{f[j]}, 其中１ <= j <= n
 */

//时间复杂度O(n), 空间复杂度O(1)
int max_sub_array(vector<int>& nums)
{
    int ret = INT32_MIN;
    int f = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        f = max(f + nums[i], nums[s]);
        ret = max(ret, f);
    }
    return ret;
}
