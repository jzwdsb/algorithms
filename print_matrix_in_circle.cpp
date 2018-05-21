//
// Created by manout on 18-5-21.
//

#include "all_include.h"

void print(int);
void print_matrix_circle(vector<vector<int>>& mat, int start);

void print_matrix_in_circle(vector<vector<int>>& mat)
{
    size_t rows = mat.size();
    size_t cols = mat[0].size();
    int start = 0;
    while (2 * start < rows and 2 * start < cols)
    {
        print_matrix_circle(mat, start);
        ++start;
    }
}

void print_matrix_circle(vector<vector<int>>& mat, int start)
{
    size_t endY = mat.size() - start - 1;
    size_t endX = mat[0].size() - start - 1;
    /** 打印第一行，总是有*/
    for (int i = start; i <= endY; ++i)
    {
        print(mat[start][i]);
    }
    /** 打印右侧一列，当起始行小于终止行时可以打印，至少有两行*/
    if (start < endY)
    {
        for (int i = start + 1; i <= endY; ++i)
        {
            print(mat[i][endX]);
        }
    }
    /** 打印下侧一行，当起始列小于终止列时可以打印，至少有两行两列*/
    if (start < endY and start < endX)
    {
        for (int i = endX - 1; i >= start; --i)
        {
            print(mat[endY][i]);
        }
    }
    /** 打印最后一列，至少有三行两列可以打印*/
    if (start < endX and start < endY - 1)
    {
        for (int i = endY - 1; i < start; --i)
        {
            print(mat[i][start]);
        }
    }
}

void print(int)
{

}