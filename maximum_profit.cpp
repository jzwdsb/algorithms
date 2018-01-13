//
// Created by manout on 18-1-13.
//
#include <algorithm>
#include <vector>
#include <climits>


int maximum_profit(const std::vector<int>& data)
{
	int maxv = INT_MIN;
	int minv = data[0];
	for (int i = 1; i < data.size(); ++ i)
	{
		maxv = std::max(maxv, data[i] - minv);
		minv = std::min(minv, data[i]);
	}
	return maxv;
}
