//
// Created by manout on 18-1-21.
//

#include "common_use.h"


static vector<int> data;

bool solve(int i, int m)
{
	if (m == 0)
		return true;
	if (i >= data.size())
		return false;
	return solve(i + 1, m) or solve (i + 1, m - data[i]);
}

