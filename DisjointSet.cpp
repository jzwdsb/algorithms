//
// Created by manout on 17-8-3.
//

#include "DisjointSet.h"

DisjointSet::DisjointSet(size_t eleCount)
{
   reset(eleCount);
}

void DisjointSet::reset(size_t eleCount)
{
    this->set_count = eleCount;
    this->rank.resize(eleCount, 1);
    reTable.resize(eleCount);
    while(eleCount != 0u)
    {
        --eleCount;
        reTable[eleCount] = eleCount;
    }
}

size_t DisjointSet::find_set(size_t x)
{
    if (reTable[x] not_eq x)
    {
        return reTable[x] = find_set(reTable[x]);
    }
    return reTable[x];

}

bool DisjointSet::isSameSet(size_t x, size_t y)
{
    return find_set(x) == find_set(y);

}

size_t DisjointSet::set_size(size_t x)
{
    return rank[find_set(x)];
}

DisjointSet &DisjointSet::unite_set(size_t x, size_t y)
{
    link_set(find_set(x), find_set(y));
}

size_t DisjointSet::count_set()
{
    return set_count;
}

void DisjointSet::link_set(size_t x, size_t y)
{
    if(x not_eq y)
    {
        if(rank[x] >= rank[y])
        {
            reTable[y] = x;
            rank[x] += rank[y];
        }
        else
        {
            reTable[x] = y;
            rank[y] += rank[x];
        }
        --set_count;
    }
}


