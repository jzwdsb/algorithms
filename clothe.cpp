#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;
using std::cout;

string analy(const string& pattern)
{
    auto front = pattern.begin();
    auto back = pattern.end() - 1;
    string ret;
    while(front not_eq pattern.end())
    {
        while (isalpha(*front))
        {
            ret.push_back(*front);
            ++front;
        }
        if (isdigit(*front))
        {
            int num = *front - '0';
            ++front;
            if (*front == '(')
            {
                while (*back not_eq ')')
                {
                    --back;
                }
                string t = analy(string(front + 1, back + 1));
                for (int i = 0; i < num - 1; ++i)
                {
                    ret += t;
                }
                front = back + 1;
                if (front == pattern.end())
                {
                    return ret;
                }
            } else
            {
                ret += string(num, *front);
            }
        }
    }
    /*
//     else
//        {
//            while ( isalpha(*front))
//            {
//                ret.push_back(*front);
//                ++front;
//            }
//        }
//        while (not isdigit(*front))
//        {
//            ret.push_back(*front);
//            ++front;
//        }
//        if (front == pattern.end())
//        {
//            return ret;
//        }
//        if (isdigit(*front))
//        {
//            ret += analy(string(front + 1, back));
//        }
//    }
 */
    return ret;
}


int main() {
    int N;
    cin>>N;
    vector<string> pat(N);
    vector<string> ret(N);
    for(size_t i = 0 ; i < N; ++i)
    {
        cin>>pat[i];
    }
    for(size_t i = 0; i < N; ++i)
    {
        ret[i] = analy(pat[i]);
    }
    for(size_t i = 0; i < N; ++i)
    {
        cout<<ret[i]<<std::endl;
    }
    return 0;
}