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
    stringstream string_list;
    string ret;
    // stringstream　会使用空格和换行符作为分割字符串
    while(string_list << sentence)
    {
        string_list >> buffer;
        ret += buffer;
    }
    return ret;
}