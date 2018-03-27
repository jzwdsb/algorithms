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

int main()
{
    freopen("/home/manout/algorithms/niuniubag.testdata", "r", stdin);
    cin >> n >> w;
    snacks.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> snacks[i];
    bag(w, n - 1);
    cout << count_;
}