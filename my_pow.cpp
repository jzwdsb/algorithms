//
// Created by manout on 17-3-17.
//

/*
 * 分治法的简单练习，
 */

double power(double , int);

//时间复杂度 O(log n)
double my_pow(double x, int n)
{
    if(n < 0)return power(x, -n);
    else return power(x, n);
}


double power(double x, int n)
{
    //先处理朴素情况
    if (n == 0)return 1;
    int sq = power(x, n / 2);
    if(n & 0x01)return sq * sq * x;
    else return sq * sq;
}
