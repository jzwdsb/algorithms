//
// Created by manout on 17-3-22.
//

#include "common_use.h"

/*
 *      Given a triangle, find the minimum path sum from top to bottom. Each step you may
 * move to adjacent numbers on the below.
 *      分析：
 *          设状态为f(i, j)，表示从位置(i, j)出发，路径的最小和，则状态转移方程为：
 *                 f(i, j) = min{f(i + 1， j), f(i + 1, j + 1)} + (i, j)
 *      算法是从三角型底部向上走使用递推公式，回溯到三角形顶部时便已求出最小路径和
 */

//时间复杂度 O(n ^ 2) 空间复杂度O(1)
int triangle(vector<vector<int>> &triangle)
{
    for (int i = triangle.size() - 2; i >= 0; ++i)
    {
        //因为这是个三角形向量，所以第 i 行有 i 个元素
        for (int j = 0; j < i; ++j) {
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}
