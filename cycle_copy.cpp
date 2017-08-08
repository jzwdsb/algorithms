//
// Created by manout on 17-8-8.
//


#include <algorithm>

std::vector<int> cycle_move(const std::vector<int>& nums, int step)
{
    std::vector<int> ret(nums.size(), 0);
    std::copy(ret.begin() + step, ret.end(), nums.begin());
    std::copy(ret.begin(), ret.begin() + step, nums.end() - step);
    return ret;
}