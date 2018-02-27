//
// Created by manout on 18-2-27.
//

#include "DisjointSet.h"
#include <string>

/** 连通块问题
 *    这里假设上下左右相邻即为连通
 * 　 假设是在矩阵中求 @ 连通个数
 * */


using Map = std::vector<std::string>;

static std::vector<std::vector<int>> flag;

static int dfs(Map& map, int x, int y)
{
    if (x >= map.size() or y >= map[0].length() or x < 0 or y < 0 or flag[x][y] == 1 or map[x][y] not_eq '@')
    {
        return 0;
    }else
    {
        int counter = 1;
        flag[x][y] = 1;
        counter += dfs(map, x - 1, y);
        counter += dfs(map, x + 1, y);
        counter += dfs(map, x, y - 1);
        counter += dfs(map, x, y + 1);
        return counter;
    }
    
}


int connected_blocks(Map& map)
{
    flag.resize(map.size(), std::vector<int>(map[0].length(), 0));
    int ans = 0;
    for (int x = 0; x < map.size(); ++x)
    {
        for (int y = 0; y < map[x].length(); ++y)
        {
            if (dfs(map, x, y) not_eq 0)
            {
                ++ans;
            }
        }
    }
    return ans;
}