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

//设状态f[i][j],表示从起点到达(i, j)的路线条数,则状态转移方程为
//	f[i][j] = f[i - 1][j] + f[i][j - 1]

//动态规划，滚动数组
//时间复杂度 O( n ^ 2)，空间复杂度 O(n)
int unique_path__(int m, int n)
{
	vector<int> f(n，0)
	f[0] = 1;
	for(int i = 0; i < m; ++i)
	{
		for(int j = 1; j < n; ++j)
		{
			//左边的f[j]表示新的f[j]，与公式中的f[i][j]对应
			//右边的f[j]表示旧的f[j]，与公式中的f[i - 1][j]对应
			f[j] = f[j] + f[j - 1]
		}
	}
	return f[n - 1];
}
/*
 *		一个m行n列的矩阵，机器人从左上走到右下需要m + n - 2步，于是题目变成机器人在其中的 m - 1处向右走一步
 *	或者在 n - 1处向下走一步的选择，根据排列组合公式 C (m - 1, m + n - 2)
 */

int64_t factor(int n, int start = 1)
{
	int64_t ret = 1;
	for (int i = start; i < n ; ++i)
	{
		ret *= i;
	}
	return ret;
}

int64_t combination(int n, int k)
{
	//常数优化
	if (n == 0)return 1;
	if (k == 1)return n;
	int64_t ret = factor(n, n - 1);
	ret /= factor(n - k);
	return ret;
}

int unique_path___(int m, int n)
{
	return combination(m + n - 2, max(m - 1, n - 1));
}
