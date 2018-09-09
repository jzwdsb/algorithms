//
// Created by manout on 18-9-9.
//

#include <iostream>
#include <vector>

using Map = std::vector<std::vector<int>>;

std::vector<std::vector<int>> flag;

int dfs(Map& map, int x, int y)
{
    if (x >= map.size() or y >= map[0].size() or x < 0 or y < 0 or flag[x][y] == 1 or map[x][y] == 0)
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
    flag.resize(map.size(), std::vector<int>(map[0].size(), 0));
    int ans = 0;
    for (int x = 0; x < map.size(); ++x)
    {
        for (int y = 0; y < map[x].size(); ++y)
        {
            int block = dfs(map, x, y);
            if (block not_eq 0)
            {
                ++ans;
            }
        }
    }
    return ans;
}

int main()
{
    freopen("/home/manout/algorithms/bytedance_connect_block.testdata", "r", stdin);
    int m;
    std::cin >> m;
    Map map(m, std::vector<int>(m, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> map[i][j];
        }
    }
    std::cout << connected_blocks(map);
}