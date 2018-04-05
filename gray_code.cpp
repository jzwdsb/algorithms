//
// Created by manout on 18-4-5.
//

#include <vector>
#include <string>
#include <cmath>

using namespace std;

/** n + 1 位格雷码的集合 = n 位格雷码集合(顺序)加前缀 0 + n 位格雷码集合(逆序) + 前缀 1*/

vector<string> getGray(int n)
{
    string zero = "0";
    string one = "1";
    vector<string> code(static_cast<unsigned long>(pow(2, n)));
    if (n == 1)
    {
        code[0] = zero;
        code[1] = one;
        return code;
    }
    vector<string> prefix = getGray(n - 1);
    auto half = code.size() / 2;
    for (int i = 0; i < half; ++i)
    {
        code[i] = zero + prefix[i];
        code[i + half] = one +  prefix[prefix.size() - i];
    }
    return code;
}
