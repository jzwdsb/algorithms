//
// Created by manout on 18-3-25.
//

#include <numeric>
#include <vector>
#include <algorithm>

using std::vector;
using std::accumulate;
using std::max;

int double_core_process(vector<int>& data)
{
    using Matrix = vector<vector<int>>;
    std::for_each(data.begin(), data.end(), [](int& a){a = a / 1024;});
    int sum = accumulate(data.begin(), data.end(), 0);
    int len = sum / 2;
    Matrix mat (data.size() + 1, vector<int>(len + 1, 0));
    for (int i = 1; i < data.size() + 1; ++i)
    {
        for (int w = 1; w < len + 1; ++w)
        {
            if (data[i] > w)
                mat[i][w] = mat[i - 1][w];
            else
                mat[i][w] = max(mat[i - 1][w], data[i] + mat[i - 1][w - data[i]]);
        }
    }
    /** 返回两个核中的较长处理时间*/
    return max(mat[data.size()][len], sum - mat[data.size()][len]) * 1024;
}
