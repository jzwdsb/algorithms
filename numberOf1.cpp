//
// Created by manout on 18-5-6.
//

#include <bits/stdc++.h>

using namespace std;

int numberOf1(int n)
{
    int tmp;
    tmp = n
          - ((n >> 1) & 033333333333)
          - ((n >> 2) & 011111111111);
    tmp = (tmp + (tmp >> 3)) & 030707070707;
    return tmp % 63;
}