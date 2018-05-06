//
// Created by manout on 18-5-6.
//

#include "all_include.h"

/**
 *  总的就是求字符串里面子字符串出现的次数，根据样例子字符串可以重叠
 * */

vector<pair<string, int>> HDU_3065(vector<string>& virus, string& text)
{
    vector<pair<string, int>> ans;
    for (auto& v : virus)
    {
        int count = 0;
        int pos = 0;
        while ((pos = text.find(v, pos)) not_eq string::npos)
        {
            ++pos;
            ++count;
        }
        if (count not_eq 0)
            ans.emplace_back(v, count);
    }
    return ans;
}
