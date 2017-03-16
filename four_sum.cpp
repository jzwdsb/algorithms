//
// Created by manout on 17-3-9.
//

#include "common_use.h"


/*
 *      Given an array S of n integers, are there elements a, b, c and d in S such
 * a + b + c + d == target? Find all unique quadruplets in the array which gives
 * the sum if target.
 *      Note:
 *          Element in quadruplet (a, b, c, d) must be in non-descending order.
 *          The solution set must not contain duplicate quadruplets.
 *      分析：
 *          先排序，然后左右夹逼，复杂度O(n3)，会超时
 *          可以用一个hash map 先缓存两个数的和，最终复杂度O(n2),这个策略也使用于3_sum
 *
 */

//暴力求解，先排序，然后左右夹逼，时间复杂度O(n3)，空间复杂度O(1)
vector<vector<int>> four_sum(vector<int> &nums, int target){
    vector<vector<int>> result;
    if(nums.size() < 4)return result;
    sort(nums.begin(), nums.end());

    auto last = nums.end();
    for(auto a = nums.begin(); a < prev(last, 3); ++a){
        for (auto b = next(a); b < prev(last, 2); ++b) {
            auto c = next(b);
            auto d = prev(last);
            while(c < d){
                if(*a + *b + *c + *d < target){
                    ++c;
                }
                else if(*a + *b + *c + *d > target ){
                    --d;
                }
                else if(*a + *b + *c + *d == target){
                    result.push_back({*a, *b, *c, *d});
                    ++c,--d;
                }
            }
        }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(),result.end()), result.end());
    return result;
}


//用一个hasp map来缓存中间结果
//时间复杂度，平均O(n2)，最坏O(n4)，空间复杂度O(n2)
vector<vector<int>>four_sum_hashmap(vector<int> &nums, int target){
    vector<vector<int>> result;
    if(nums.size() < 4) return result;
    sort(nums.begin(), nums.end());

    unordered_map<int, vector<pair<int, int>>> cache;
    for(size_t a = 0; a < nums.size(); ++a){
        for(size_t b = a + 1; b < nums.size(); ++b){
            cache[nums[a] + nums[b]].push_back(make_pair(a,b));
        }
    }

    for(size_t c = 0; c < nums.size(); ++c){
        for (size_t d = c + 1; d < nums.size(); ++c){
            const int key = target - nums[c] - nums[d];
            if(cache.find(key) == cache.end()) continue;
            const auto& vec = cache[key];
            for (size_t k = 0; k < vec.size(); ++k) {
                if (c < vec[k].second)continue;
                result.push_back({nums[vec[k].first], nums[vec[k].second], nums[c], nums[d]});
            }
        }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;

}