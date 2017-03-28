//
// Created by manout on 17-3-28.
//

#include "common_use.h"
/*
 *      You are given an n * n 2D matrix representing an image
 *      Rotate the image by 90 degrees (clockwise)
 *      note: do it in place
 *      分析：　可以根据定义顺时针操纵每个元素旋转９０度，但是太慢了，实践起来也麻烦
 *      可以先沿副对角线翻折，然后再上下翻折
 */


void rotate_image(vector<vector<int>> &matrix)
{
    const int n = matrix.size();

    //先沿副对角线翻折
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
        {
            swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);
        }
    }

    //再上下翻折
    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            swap(matrix[i][j], matrix[n - i - 1][j]);
        }
    }
}
