//
// Created by manout on 18-3-13.
//

#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

using std::max;

int longest_common_substring(string& a, string& b)
{
    vector<vector<int>> mat(a.length() + 1, vector<int>(b.length() + 1, 0));
    for (int i = 0; i < a.length(); ++ i)
    {
        for (int j = 0; j < b.length(); ++j)
        {
            if (a[i] == b[j])
            {
                mat[i + 1][j + 1] = mat[i][j] + 1;
            }else
            {
                mat[i + 1][j + 1] = max(mat[i][j + 1], mat[i + 1][j]);
            }
        }
    }
    return mat[a.length()][b.length()];
}

int construct_palindromes(string str)
{
    string r_str;
    r_str.resize(str.length());
    std::reverse_copy(str.begin(), str.end(), r_str.begin());
    return str.length() - longest_common_substring(str, r_str);
}