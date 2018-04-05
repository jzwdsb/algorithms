//
// Created by manout on 18-3-27.
//



#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int w;
int count_ = 1;
vector<int> snacks;

void bag(int w, int i)
{
    //sort(snacks.begin(), snacks.end());
    //vector<vector<int>> mat(snacks.size() + 1, vector<int>(w + 1, 0));
    if (i < 0)return ;
    if (w == 0)
    {
        ++count_;
        return;
    }
    if (snacks[i] > w )
    {
        bag(w, i - 1);
        return ;
    }
    if (snacks[i] < w)
    {
       ++count_;
       bag(w - snacks[i], i - 1);
       bag(w, i - 1);
    }
   
}

