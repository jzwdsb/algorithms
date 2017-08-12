//
// Created by manout on 17-8-8.
//


#include <algorithm>

std::vector<int> cycle_move(const std::vector<int>& nums, int step)
{
    std::vector<int> ret(nums.size(), 0);
    std::copy(nums.begin(), nums.end() - step, ret.begin() + step);
    std::copy(nums.end() - step, nums.end(), ret.begin());
    return ret;
}