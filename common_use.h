//
// Created by manout on 17-3-12.
//

#ifndef LEETCODE_COMMON_USE_H
#define LEETCODE_COMMON_USE_H

#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <cmath>

using std::string;
using std::vector;
using std::stack;

using std::reverse;
using std::next;
using std::prev;
using std::reverse_iterator;
using std::max;
using std::find;
using std::bind1st;
using std::swap;
using std::sort;
using std::begin;
using std::end;
using std::distance;
using std::min;

struct Point
{
    int x;
    int y;
    Point():x(0), y(0){}
    Point(int x, int y):x(x), y(y){}
    Point operator-(Point& b)
    {
        return {this->x - b.x, this->y - b.y};
    }
    int sum()
    {
        return this->x + this->y;
    }
};

#endif //LEETCODE_COMMON_USE_H
