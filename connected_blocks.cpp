//
// Created by manout on 18-2-27.
//

#include <queue>
#include <string>
#include <iostream>


using std::queue;
using std::string;
using std::vector;

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


struct Node
{
    int x;
    int y;
};

int bfs(Map& map, int x, int y)
{
    int dir[4][2]= {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    if (flag[x][y] == 1 or map[x][y] not_eq '@')return 0;
    int ans = 1;
    queue<Node> q;
    Node node;
    node.x = x;
    node.y = y;
    q.push(node);
    flag[x][y] = 1;
    while (not q.empty())
    {
        Node curr = q.front();q.pop();
        Node next;
        for (int i = 0; i < 4; ++i)
        {
            next.x = curr.x + dir[i][0];
            next.y = curr.y + dir[i][1];
            if (next.x >= map.size() or next.y >= map[0].length()
                or next.x < 0 or next.y < 0 or flag[next.x][next.y] == 1
                or  map[next.x][next.y] not_eq  '@')
            {
                continue;
            }else
            {
                flag[next.x][next.y] = 1;
                q.push(next);
                ++ans;
            }
            
        }
    }
    return ans;
}

int disbfs(Map& map, int x, int y)
{
    int dir[4][2]= {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    if (flag[x][y] == 1 or map[x][y] not_eq '@')return 0;
    int ans = 1;
    queue<Node> q;
    Node node;
    node.x = x;
    node.y = y;
    q.push(node);
    flag[x][y] = 1;
    while (not q.empty())
    {
        Node curr = q.front();q.pop();
        Node next;
        for (int i = 0; i < 4; ++i)
        {
            next.x = curr.x + dir[i][0];
            next.y = curr.y + dir[i][1];
            if (next.x >= map.size() or next.y >= map[0].length()
                or next.x < 0 or next.y < 0 or flag[next.x][next.y] == 1
                or  map[next.x][next.y] not_eq  '@')
            {
                continue;
            }else
            {
                flag[next.x][next.y] = 1;
                q.push(next);
                ++ans;
            }
            
        }
    }
    return ans;
}

int connected_blocks(Map& map)
{
    flag.resize(map.size(), std::vector<int>(map[0].length(), 0));
    int ans = 0;
    for (int x = 0; x < map.size(); ++x)
    {
        for (int y = 0; y < map[x].length(); ++y)
        {
            int block = disbfs(map, x, y);
            if (block not_eq 0)
            {
                ++ans;
            }
        }
    }
    return ans;
}