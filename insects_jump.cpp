//
// Created by manout on 18-2-1.
//

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

/** 实现循环数组*/
#define INDEX(i) (((i) + 9) % 9)


static int steps = 0;
/** 图的点集， 每产生一个状态就将当前状态点加入到点集中*/
static std::unordered_set<std::string> graph;
static std::string start;
static std::string end ;


static std::queue<std::string> layer;
static int layer_count = 0;

/** 这个函数产生当前状态经一步转移可到达的所有状态插入到 layer 之后*/
static bool breadth_search(const std::string& node)
{
    int empty_pos = static_cast<int>(node.find('0'));
    for(int i = empty_pos - 2; i < empty_pos + 2; ++i)
    {
        std::string child = node;
        std::swap(child[INDEX(i)], child[INDEX(empty_pos)]);
        if (child == "087654321")
        {
            layer.push(child);
            return true;
        }
        /** 避免重复搜索判断当前状态是否已经存在于图中*/
        if (graph.count(child) == 0)
        {
            layer.push(child);
            graph.insert({child});
        }
    }
    return false;
}

int insect_jump()
{
    start = "012345678";
    end = "087654321";
    layer.push(start);
    graph.insert({start});
    layer_count = 1;
    /** 当到达目的状态时，搜索结束*/
    while (true)
    {
        /** 当前层搜索完毕，进入下一层*/
        if (layer_count == 0)
        {
            ++steps;
            layer_count = static_cast<int>(layer.size());
        }
        std::string node = layer.front();layer.pop();
        if (breadth_search(node))
        {
            break;
        }
        --layer_count;
    }
    return steps;
}
