//
// Created by manout on 18-3-15.
//

#include <string>
#include <algorithm>

using std::string;
using std::rotate;

string& capital_rotate(string& str)
{
    string::iterator rotate_end = str.end();
    for (string::iterator it = str.begin(); it not_eq rotate_end; ++it)
    {
        if (isupper(*it))
        {
            auto next_lower = it;
            while (isupper(*next_lower) and next_lower not_eq rotate_end)++next_lower;
            if (next_lower == rotate_end)return str;
            rotate(it, next_lower, str.end());
            --rotate_end;
        }
    }
    return str;
}