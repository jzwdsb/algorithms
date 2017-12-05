#include <iostream>
#include <string>
bool judege(const std::string& str);

/**
     str = A(n)PATA(n)
     str = A(n)PA(b)TA(b * n)
     应该是这样的
*/

bool judege(const std::string& str)
{
    int prefix = 0;
    int infix = 0;
    int postfix = 0;
    std::string::const_iterator it = str.begin();
    while (it != str.end() && *it == 'A' )
    {
            ++it;
            ++prefix;
    }
    if (it == str.end() || *it != 'P')
    {
        return false;
    }
    ++it;
    if(it == str.end() || *it != 'A')
    {
        return false;
    }
    infix = 1;
    while (it != str.end() && *it == 'A')
    {
        ++it;
        ++infix;
    }
    if (it == str.end() || *it != 'T')
    {
        return false;
    }
    ++it;
    while (it != str.end() && *it == 'A')
    {
        ++it;
        ++postfix;
    }
    if (it == str.end() && postfix == prefix * infix)
    {
        return true;
    }
    return false;

}

int main()
{
    int n;
    std::string str;
    std::cin >> n;

    while (n--)
    {
        std::cin >> str;
        std::cout << (judege(str) ? "YES" : "NO") <<std::endl;
    }
}
