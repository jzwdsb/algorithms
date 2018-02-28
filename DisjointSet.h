//
// Created by manout on 17-8-3.
//

#ifndef ALOGRITHMS_DISJOINTSET_H
#define ALOGRITHMS_DISJOINTSET_H


#include <glob.h>
#include <vector>

class DisjointSet
{
public:
    DisjointSet() = default;
    explicit DisjointSet(size_t eleCount);

    void reset(size_t eleCount);
    size_t find_set(size_t x);
    bool isSameSet(size_t x, size_t y);
    size_t set_size(size_t x);
    DisjointSet& unite_set(size_t x, size_t y);
    size_t count_set();

private:
    void link_set(size_t x, size_t y);
    size_t  set_count;
    std::vector<size_t> rank;
    std::vector<size_t> reTable;
};


#endif //ALOGRITHMS_DISJOINTSET_H
