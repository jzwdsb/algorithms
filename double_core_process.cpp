//
// Created by manout on 18-3-25.
//

#include <numeric>
#include <vector>
#include <algorithm>

using std::vector;
using std::find_if;
using std::accumulate;
using std::sort;
using std::swap;

int reduce(int max_, int min_, vector<int>& gr, vector<int>& le)
{
    int subs = max_ - min_;
    auto cond = [&](int num)
        {
            return num > subs and max_ - num > min_;
        };
 
    while (true)
    {
        auto pos = find_if(gr.begin(), gr.end(), cond);
        if (pos == gr.end())break;
        
    }
}

int double_core_process(vector<int> data)
{
    decltype(data) a, b;
    sort(data.begin(), data.end());
    for (int i = 0; i < data.size() - 1; i += 2)
    {
        a.push_back(data[i]);
        b.push_back(data[i + 1]);
    }
    int sum_a = accumulate(a.begin(), a.end(), 0);
    int sum_b = accumulate(b.begin(), b.end(), 0);
    if (sum_a > sum_b)
    {
        swap(sum_a, sum_b);
    }
    
}
