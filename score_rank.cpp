//
// Created by manout on 17-8-2.
//

#include <iostream>
#include <vector>
#include <string>
/*
 * 从输入中找到分数最高和最低的两位同学的学好
 * */
struct info
{
    std::string name;
    std::string ID;
    size_t score{0};
};


using result_t = std::pair<info, info>;

void get_top_last()
{
    size_t size = 0, i = 0;
    info pre, high, low;
    low.score = SIZE_MAX;
    std::cin>>size;
    if(size == 0)return;
    while(size--)
    {
        std::cin>>pre.name >> pre.ID >> pre.score;
        if (pre.score > high.score)
            high = pre;
        if (pre.score < low.score)
            low = pre;
    }
    std::cout << high.name <<' ' << high.ID<<std::endl;
    std::cout << low.name << ' ' << low.ID << std::endl;

}