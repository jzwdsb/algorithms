//
// Created by manout on 17-8-5.
//

#include <string>
#include <vector>
#include <sstream>


std::string format_number(int number)
{
    std::stringstream ss;
    std::string number_string, ret;
    std::size_t len ;
    size_t hundred, deca, last, i;
    ss << number;
    ss >> number_string;
    len = number_string.length();
    auto add_last = [&ret](size_t num)
    {
        size_t index = 0;
        do
        {
            ++index;
            ret.push_back(static_cast<char>(index + '0'));
        }while(index not_eq num);
    };
    switch (len)
    {
        case 1:
            add_last(static_cast<size_t>(number_string[0] - '0'));
            break;
        case 2:
            deca = static_cast<size_t>(number_string[0] - '0');
            last = static_cast<size_t>(number_string[1] - '0');
            ret.append(deca, 'S');
            add_last(last);
            break;
        case 3:
            hundred = static_cast<size_t>(number_string[0] - '0');
            deca = static_cast<size_t>(number_string[1] - '0');
            last = static_cast<size_t>(number_string[2] - '0');
            i = 0;
            ret.append(hundred, 'B');
            ret.append(deca, 'S');
            add_last(last);
            break;
        default:break;
    }

    return ret;
}


