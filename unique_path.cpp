//
// Created by manout on 17-3-23.
//

#include "common_use.h"

/*
 *      A robot is located at the top-left corner of a m ×　n grid(marked 'Start' in the diagram below)
 *      the robot can only move either down or right at any point in time. The robot is trying to reach
 *  the bottom-right corner of the grid(marked 'Finish' in the diagram below)
 *      How many unique path are there ?
 */

//深度优先搜索，数量大时会超时，时间复杂度O(n ^ 4)，空间复杂度O(n)
int unique_path(int m, int n)
{
    //处理越界情况
    if(m == 0 or n == 0)
    {
        return 0;
    }
    //处理到达终点情况
    if(m == 1 and n == 1)
    {
        return 1;
    }
    //从当前一点到终点的不同路线等于下面一点到终点的不同路线加上右面一点到终点的不同路线
    return unique_path(m - 1, n) + unique_path(m, n - 1);
}


static vector<vector<int>> f;

//在深搜的基础上加上备忘录，即是备忘录法，大集合便能通过
int unique_path_(int m, int n)
{
    f = vector<vector<int>> (m, vector<int>(n, 0));
    f[0][0] = 1;
    return dfs(m - 1, n - 1);
}

int dfs(int x, int y)
{
    if ( x < 0 or y < 0)return 0;
    if (x == 0 and y == 0) return f[0][0];
    if(f[x][y] > 0)return f[x][y];
    return f[x][y] = dfs(x - 1, y) + dfs(x, y - 1);
}