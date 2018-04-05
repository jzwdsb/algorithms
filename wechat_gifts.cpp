//
// Created by manout on 18-4-5.
//

#include <map>
#include <vector>

using namespace std;


int getValue(vector<int> gifts, int n)
{
    map<int, int> count;
    for (int v : gifts)
    {
        ++count[v];
    }
    for (auto pair : count)
    {
        if (pair.second > n / 2 )
        {
            return pair.first;
        }
    }
    return 0;
}
