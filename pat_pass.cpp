//
// Created by manout on 17-8-1.
//

#include <string>
#include <regex>
#include <regex.h>

using std::regex;
bool judge_regular(std::string &src,
        const regex& pattern = regex(R"==(.*?(p*?a*?t*?).*?)==", regex::icase) )
{
    std::match_results<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::iterator> result;
    return regex_match(src.begin(), src.end(), result, pattern,
            std::regex_constants::match_not_null);

}
