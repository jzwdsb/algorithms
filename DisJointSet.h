#pragma once
#include "all_include.h"

class DisJointSet
{
public:
	DisJointSet() :set_count(0) {}
	DisJointSet(size_t size) :rank(size, 1), reTable(size) { for (auto i = 0; i < size; ++i) makeSet(i); }

	int findSet(int index)
	{	
		if (index == reTable[index])
			return index;
		
		return reTable[index] = findSet(reTable[index]);
	}

	bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }

	size_t countElement(int x) { return rank[findSet(x)]; }

	void unite_Set(int x, int y) { link(findSet(x), findSet(y)); }

	size_t count_set() { return set_count; }
private:	
	void makeSet(size_t index) { reTable[index] = index; }
	
	void link(int x, int y)
	{
		if (x != y)
		{
			if (rank[x] > rank[y])
			{
				reTable[y] = x;
				rank[x] += rank[y];
			}
			else if (rank[x] < rank[y])
			{
				reTable[x] = y;
				rank[y] += rank[x];
			}
			else { reTable[y] = x; rank[x] += y; }
			--set_count;
		}

	}

	size_t set_count;
	std::vector<size_t> rank;
	std::vector<int> reTable;
};