//
// Created by manout on 17-3-7.
//
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

#define not_eq  !=
#define and     &&
/*
 *      Given an array S of integers, are there element a, b, c in S such that
 *  a + b + c = 0? Find all unique triplets in the array which gives the sum of
 *  zero.
 *      Note:
 *          Elements in triplet (a, b, c) must be in non-descending order.
 *          The solution set must not contain duplicate triplets.
 *          For example, given array S = {-1, 0, 1, 2, -1, -4}
 *          A solution is :
 *              (-1, 0, 1) (-1, -1, 2)
 *      分析：
 *          应该先排序，然后左右夹逼，复杂度O(n2)。
 *          这个方法k可以推广到k-sum，先排序，然后做 k - 2次循环，在最内层左右夹逼，时间复杂度
 *          是O(max{n log n, n(k - 1)});
 * */

vector<vector<int>> three_sum(vector<int> &nums){
    vector<vector<int>> result;
    if(nums.size() < 3) return result;
    sort(nums.begin(), nums.end());
    const int target  = 0;

    auto last = nums.end();
    for(auto i = nums.begin(); i < last - 2; ++i){
        auto j = i + 1;
        if( i > nums.begin() and *i == *(i - 1))continue;
        auto k = last - 1;
        while(j < k){
            //如果小于0，那么将第二个迭代器向后移动一位，也就是中间的数增大
            if (*i + *j + * k < target) {
                ++j;
                //跳过相同的数
                while (*j == *(j - 1) and j < k)++j;
            }
            //如果大于0，将第三个迭代器向前移动一位，也就是最大的数减小
            else if (*i + *j + *k > target) {
                --k;
                while (*k == *(k + 1) and j < k) --k;
            }
            //将符合结果的组合压入result尾部，其余两个迭代器,跳过相同的数
            else{
                result.push_back({*j, *j, *k});
                ++j, --k;
                while(*j == *(j - 1) and *k == *(k + 1) and j < k) ++j, --k;
            }
        }
    }

    return result;
}
