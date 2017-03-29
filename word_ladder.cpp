//
// Created by manout on 17-3-29.
//

#include "common_use.h"

/*
 *      Given two words(start and ends), and a dictionary, find the length of shortest transformation
 * sequence from start to end
 *      分析：
 *          使用广度优先搜索
 */
//定义节点类，表示当前的字符串信息和到start 的步数
struct state_t
{
    int level;
    string word;
    state_t():level(0), word(){}
    state_t(int level, const string& word):level(level),word(word){}
    bool operator== (const state_t& state)
    {
        return this -> word == state.word;
    }
};
//添加自定义类的hash函数
template<>
struct hash<state_t>
{
public:
    size_t operator()(const state_t &state)
    {
        return str_hash(state.word);
    }

private:
    std::hash<std::string> str_hash;
};



int ladder_length(const string& start, const string& end, const unordered_map& dict)
{
    queue<state_t> q;
    unordered_set<state_t> visited;
    //判断当前访问的状态是否可以加入到队列和已访问记录中
    auto state_is_valid = [&](const state_t& s)
    {
        return dict.find(s.word) not_eq dict.end() or s.word == end
    };
    //判断当前状态是不是终点
    auto state_is_target = [&](const state_t& s)
    {
        return s.word == end;
    };
    //从当前访问节点开始访问下一层，返回一个包含下一层元素的容器
    auto state_extend = [&](const state_t& s)
    {
        unordered_set<state_t> result;
        for (int i = 0; i < s.word.length(); ++i)
        {
            state_t new_state = state_t(s.level + 1, s.word );
            for (char c = 'a'; c < 'z'; ++c)
            {
                if(c == new_state.word[i])continue;
                swap(c, new_state.word[i]);
                if(state_is_valid(new_state) and visited.find(new_state) == visited.end())
                {
                    visited.insert(new_state);
                }
                swap(c, new_state.word[i]);
            }
        }
        return result
    };
    state_t start_state(0,start);
    q.push(start_state);
    visited.insert(start_state);
    while(not q.empty())
    {
        const auto state = q.front();
        q.pop();
        if(state_is_target(state))
        {
            return start_state.level + 1;
        }
        const auto new_state = state_extend(state);
        for (const auto& s : new_state)
        {
            q.push(s);
            visited.insert(s);
        }
    }
    return 0;

}
