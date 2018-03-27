//
// Created by manout on 18-3-27.
//

#include <string>
#include <algorithm>

#define SUM(A)  ((A) * (A - 1) / 2)

using namespace std;

int adjust_team(string& team)
{
    int boy = 0, girl = 0, boy_sum  = 0, girl_sum = 0;
    for (int i = 0; i < team.length(); ++i)
    {
        if (team[i] == 'B')
        {
            ++boy;
            boy_sum += i;
        }
        else
        {
            ++girl;
            girl_sum += i;
        }
    }
    return min(boy_sum - SUM(boy), girl_sum - SUM(girl));
}