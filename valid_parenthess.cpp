//
// Created by manout on 17-3-12.
//

#include "common_use.h"


bool is_valid(const string &s){
    string left = "([{";
    string right = ")]}";

    stack<char> stk;

    for(auto c : s){
        if(left.find(c) not_eq string::npos){
            stk.push(c);
        }else{
            if (stk.empty() or stk.top() not_eq left[right.find(c)])
                return false;
            else
                stk.pop();
        }
    }
    return stk.empty();
}