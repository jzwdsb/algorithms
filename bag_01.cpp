//
// Created by manout on 18-3-25.
//

#include <vector>
#include <set>

using namespace std;

vector<int> data;


/** i 表示第 i 个物品， w 表示当前的剩余容量，*/
int P(int i, int W, vector<int>& w, vector<int>& v)
{
    if (i == 0)
        return 0;
    if (W == 0)
        return 0;
    if (w[i] > W)
        return P(i - 1, W, w, v);
    return max(P(i - 1, W, w, v), v[i] + P(i - 1, W - w[i], w, v));
}

/** @param W 各物体重量
 *  @param V 各物体价值
 *  @param C 背包总容量
 * */
int P(vector<int>& W, vector<int>& V, int C)
{
    using Matrix = vector<vector<int>>;
    Matrix mat (W.size() + 1, vector<int>(C + 1, 0));
    for (int i = 1; i <= W.size() ; ++i)
    {
        for (int w_ = 1; w_ <= C; ++w_)
        {
            if (W[i] > w_)
                mat[i][w_] = mat[i - 1][w_];
            else
                mat[i][w_] = max(mat[i - 1][w_], V[i] + mat[i - 1][w_ - W[i]]);
        }
    }
    return mat[W.size()][C];
}