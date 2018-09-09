//
// Created by manout on 18-9-6.
//

#include <string>
#include <set>
#include <iostream>

unsigned long longest_sub_string(const std::string& str)
{
    std::set<char> char_set;
    for (auto ch : str)
    {
        char_set.insert(ch);
    }
    return char_set.size();
}


int main()
{
    std::string input;
    std::cin >> input;
    std::cout << longest_sub_string(input);
}
