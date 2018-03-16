//
// Created by manout on 18-3-15.
//

#include <vector>
#include <map>

#include <algorithm>

using std::map;
using std::vector;
using std::pair;

using std::sort;
using std::make_pair;

using ans_type = pair<int, int>;

int fact(int n)
{
    if (n == 1 or n == 0)return 1;
    int ans = 1;
    for (int i = 2; i < n + 1; ++i)
    {
        ans *= i;
    }
    return ans;
}

int combin(int n, int m)
{
    return fact(n) / (fact(m) * fact(n - m));
}

ans_type min_subs_max_subs(vector<int>& data)
{
    ans_type ans(0, 0);
    vector<int> subs;
    sort(data.begin(), data.end());
    int sub_max;
    int front_count = 0, back_count = 0;
    front_count = static_cast<int>(std::count(data.begin(), data.end(), data.front()));
    back_count = static_cast<int>(std::count (data.begin(), data.end(), data.back()));
    ans.second = front_count * back_count;
    
    auto min_pos = std::min_element(subs.begin(), subs.end());
    int min_count = static_cast<int>(std::count(subs.begin(), subs.end(), *min_pos));
    auto new_end = std::unique(data.begin(), data.end());
    map<int, int> unique_count;
    if (new_end == data.end())
    {
        ans.first = min_count;
    }else
    {
        for (auto it = new_end; it not_eq data.end(); ++it)
        {
            if (unique_count.count(*it) == 0)
            {
                unique_count.insert(make_pair(*it, 2));
            }else
            {
                ++unique_count[*it];
            }
        }
        ans.first = 1;
        for (auto &it : unique_count)
        {
            ans.first += combin(it.second, 2);
        }
    }
    
    return ans;
}
