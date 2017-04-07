//
// Created by manout on 17-4-7.
//

/*
 *      You are climbing a stair case. It takes n steps to reach to the top.
 *      Each time you can climb 1 or 2 stairs. In how many distinct ways can you climbing
 * to the top.
 *      分析：到达第N阶可以有两种方案
 *          1: 从 n - 1 阶迈一步
 *          2: 从 n - 2 阶迈两步
 *      得递推公式： f[n] = f[n - 1] + f[n - 2]
 *      斐波那且数列
 */


#include "common_use.h"

//迭代法
int climbstairds(int n)
{
    int prev = 0;
    int cur = 1;
    for (int i = 1; i < n; ++i) {
        int tmp = cur;
        cur += prev;
        prev = tmp;
    }
    return cur;
}

//公式法
int climbstairs_(int n)
{
    const double s = sqrt(5);
    //floor 函数将传入的小数向0取整
    return floor(pow((1 + s) / 2, n + 1) + pow((1 - s) / 2, n + 1) + 0.5);
}