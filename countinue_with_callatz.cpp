//
// Created by manout on 17-8-3.
//

#include <unordered_map>
#include <vector>
std::vector<size_t> continue_with_callatz(size_t count,const std::vector<size_t>& nums )
{
    std::unordered_map<size_t, size_t > reTable;
    std::vector<size_t> ret;
    // 先构造每个树指向自己的森林
    for(auto num : nums)
        reTable[num] = num;
    for (auto num : nums)
    {
        size_t root = num;
        while(num not_eq 1)
        {
            if(num % 2 == 0)
            {
                num >>= 2;
                if (reTable.find(num) not_eq reTable.end())
                {
                    reTable[num] = root;
                }
            }
            else
            {
                num = (3 * num + 1) / 2;
                if(reTable.find(num) not_eq reTable.end())
                {
                    reTable[num] = root;
                }
            }
        }
    }
    for(auto num : nums)
    {
        if (reTable[num] == num)
        {
            ret.push_back(num);
        }
    }
    return ret;
}