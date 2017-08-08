//
// Created by manout on 17-8-8.
//


#include <string>
#include <sstream>
#include <vector>

using std::string;
using std::stringstream;

string reverse_string(const string& sentence)
{
    string buffer;
    stringstream string_split;
    std::vector<string> string_list;
    string ret;
    // stringstream　会使用空格和换行符作为分割字符串
    while(string_split << sentence)
    {
        string_split >> buffer;
        string_list.push_back(buffer);
    }
    for (auto it = string_list.rbegin(); it not_eq string_list.rend(); ++it)
    {
        ret += *it;
    }
    return ret;
}