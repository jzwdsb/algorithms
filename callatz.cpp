#include<stdio.h>
#include<iso646.h>




//卡拉兹猜想
//      对于任何一个自然数，如果他是偶数，那么把它砍掉一半，如果是奇数，那么吧(3n + 1) 砍掉一半，一直循环下去，最后一定能在
//某一步得到n = 1。


//对于给定的不超过1000的正整数n，简单的数一下，需要多少不才能得到 n = 1


int main()
{
    int n, count = 0;
    scanf("%d", &n);
    
    while(n not_eq 1)
    {
        if(n % 2 == 0)
        {
            n /=2;
        }
        else {
            n = (3 * n + 1) / 2;
        }
        ++count;
    }
    printf("%d\n", count);


    return 0;
}