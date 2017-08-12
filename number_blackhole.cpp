//
// Created by manout on 17-8-11.
//

#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using num_pair = std::pair<int, int>;
using std::vector;
using std::string;
using std::stringstream;
using std::sort;

inline
void intertostr(int a, string &str, stringstream& ss)
{
    ss << a;
    ss >> str;
    ss.clear();
}

inline
void strtointer(string& str, int &a, stringstream& ss)
{
    ss << str;
    ss >> a;
    ss.clear();
}


vector<num_pair> number_blackhole(int a)
{
    int b;
    string str, re_str;
    stringstream ss;
    vector<num_pair> ret;
    intertostr(a, str, ss);

    sort(str.begin(), str.end());

    re_str.assign(str.rbegin(), str.rend());

    strtointer(re_str, b, ss);
    strtointer(str, a, ss);
    a = b - a;
    if (a == 0)
        return ret;
    ret.emplace_back(b, a);
    while (a not_eq 6174)
    {
        intertostr(a, str, ss);
        sort(str.begin(), str.end());
        strtointer(str, a, ss);
        re_str.assign(str.rbegin(), str.rend());
        strtointer(re_str, b, ss);
        ret.emplace_back(b, a);
        a = b - a;
    }

    return ret;
}
