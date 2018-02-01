//
// Created by manout on 18-2-1.
//
#include "common_use.h"

/** 计算过程中的三种状态
 *  0 未知
 *  1 失败
 *  3 成功
 * */

#define NOPASSBY    0
#define UNKNOWN     1
#define FAILURE     2
#define SUCCESS     3


struct coordinate
{
    int x = 0;
    int y = 0;
    coordinate(int x, int y):x(x), y(y){}
};

static int escape;

static vector<vector<int>> point;


static void set_status(vector<coordinate>& path, int status)
{
    for (auto it = path.begin(); it not_eq path.end(); ++it)
    {
        point[it->x][it->y] = status;
    }
}

static void find_path(vector<string>& map, int x, int y)
{
    vector<coordinate> path;
    do
    {
        point[x][y] = UNKNOWN;
        path.emplace_back(x, y);
        switch (map[x][y])
        {
            case 'U':
                --y;
                break;
            case 'D':
                ++y;
                break;
            case 'L':
                --x;
                break;
            case 'R':
                ++x;
                break;
            default:
                break;
        }
    }while (x < map.size() and y < map[0].length() and x > 0 and y > 0 and point[x][y] == NOPASSBY);
    if (x >= map.size() or y >= map[0].length() or x < 0 or y < 0)
    {
        escape += path.size();
        set_status(path, SUCCESS);
        return;
    }
    if (point[x][y] == SUCCESS)
    {
        escape += path.size();
        set_status(path, SUCCESS);
        return ;
    }
    if (point[x][y] == UNKNOWN)
    {
        point[x][y] = FAILURE;
        set_status(path, FAILURE);
    }
}


int count_escape(vector<string>& map)
{
    escape = 0;
    point.resize(map.size(), vector<int>(map[0].length(), NOPASSBY));
    for (int i = 0; i < map.size(); ++i)
    {
        for (int j = 0; j < map[0].length(); ++j)
        {
            if (point[i][j] == NOPASSBY)
            {
                find_path(map, i, j);
            }
        }
    }
    return escape;
}