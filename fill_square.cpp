//
// Created by manout on 18-3-20.
//

#include <cstdlib>
#include <algorithm>

const int rows = 3;
const int cols = 4;

int mapp[10][10] = {-10};
bool numv[15] = {false};
int count;

int dir[4][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

static bool check(int x, int y, int n)
{
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 and nx < rows and ny >= 0 and ny <= cols)
        {
            if (abs(mapp[nx][ny] -  n) ==  1)
            {
                return false;
            }
        }
    }
    return true;
}

static void dfs(int dep, int pos)
{
    /** 2, 3 是搜索末尾且为缺口, 当前状态成立, 计数 + 1 后返回*/
    if (dep == 2 and pos == 3)
    {
        ++count;
        return ;
    }
    
    /** 当前行搜索完毕, 从下一行第一列开始搜索*/
    if (pos >= cols)
    {
        dfs(dep + 1, 0);
        return ;
    }
    for (int i = 0; i <= 9; ++i)
    {
        if (not numv[i] and check(dep, pos, i))
        {
            numv[i] = true;
            mapp[dep][pos] = i;
            dfs(dep, pos + 1);
            mapp[dep][pos] = -10;
            numv[i] = false;
        }
    }
}

int fill_square()
{
    count = 0;
    /** 0, 1 是缺口, 跳过*/
    dfs(0, 1);
    return count;
}