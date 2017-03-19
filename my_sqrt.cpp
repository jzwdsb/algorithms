//
// Created by manout on 17-3-19.
//

#include "common_use.h"

int my_sqrt(int x)
{
    int left = 1;
    int right = x / 2;          //因为x的平方根肯定在[1, x / 2]之间，所以将起始上限定为x / 2
    int last_mid;
    if (x < 2) return x;
    while(left <= right)
    {
        const int mid = left + (right - left) / 2;
        if(x / mid > mid)
        {
            //如果当前中间值的平方小于x，那么应该将搜索区域的值扩大，即提高搜索区间的下限
            left = mid + 1;
            last_mid = mid;
        } else if (x / mid < mid){
            //如果当前中间值的平方大于x，那么应该将搜索区间的值减小，即降低搜索区间的上限
            right = mid - 1;
            last_mid = mid;
        }else{
            return mid;
        }
    }
    return last_mid;
}
