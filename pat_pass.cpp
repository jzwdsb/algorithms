//
// Created by manout on 17-8-1.
//

#include <string>
#include <regex>
#include <regex.h>

using std::regex;
bool judge_regular(std::string &src,
        const regex& pattern = regex(R"==(A*?PA*?TA*?)==", regex::icase) )
{
    std::match_results<std::string::iterator> result;
    return regex_match(src.begin(), src.end(), result, pattern,
            std::regex_constants::match_not_null);

}
