//
// Created by manout on 17-8-9.
//


#include <vector>

using std::vector;

vector<int>& derivation( vector<int>& nums)
{
    vector<int>::iterator factor;
    vector<int>::iterator exponent;
    factor = nums.begin();
    exponent = factor + 1;
    while (exponent not_eq nums.end())
    {
        *factor *= *exponent;
        --*exponent;
        ++factor;
        ++exponent;
    }
    return nums;
}

