//
// Created by manout on 18-5-6.
//

#include <bits/stdc++.h>

using namespace std;

int numberOf1(int n)
{
    size_t tmp = static_cast<size_t>(n);
    tmp =
          - ((tmp >> 1) & 033333333333)
          - ((tmp >> 2) & 011111111111);
    tmp = (tmp + (tmp >> 3)) & 030707070707;
    return static_cast<int>(tmp % 63);
}