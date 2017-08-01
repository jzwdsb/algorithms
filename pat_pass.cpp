//
// Created by manout on 17-8-1.
//

#include <string>
#include <boost/regex.hpp>

using namespace boost;


bool judge_regular(std::string &src,
        const regex& pattern = regex(R"==(.*?(p*?a*?t*?).*?)==", regex::perl | regex::icase) )
{
    match_results result;
    return regex_match(src.begin(), src.end(), result, pattern, match_not_dot_null);

}
