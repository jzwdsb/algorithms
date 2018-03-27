//
// Created by manout on 18-3-27.
//

#include <iostream>
#include <string>
using namespace std;

int light(string& road)
{
    int ans = 0;
    string::iterator it = road.begin();
    while (it not_eq road.end())
    {
        while (*it == 'X' and it not_eq road.end()) ++it;
        if (it == road.end())break;
        auto e = it;
        while (*e == '.' ) ++e;
        int len = distance(it, e);
        ans += len / 3;
        if (len % 3 == 1)
        {
            if (e not_eq road.end() and *(e + 1) == '.')
            {
                ans += 1;
                e += 2;
            }else
            {
                ans += 1;
            }
        }
        if (len % 3 == 2)
            ans += 1;
        it = e;
    }
    return ans;
}


