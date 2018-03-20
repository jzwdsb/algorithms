//
// Created by manout on 18-3-20.
//

int birthday_candle()
{
    int sum;
    for (int i = 1; i < 100; ++i)
    {
        sum = 0;
        for (int j = i; j < 100; ++j)
        {
            sum += j;
            if (sum == 236)return i;
            if (sum > 236)break;
        }
    }
}
