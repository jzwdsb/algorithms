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
            rotate(it, it + 1, str.end());
            --rotate_end;
        }
    }
    return str;
}