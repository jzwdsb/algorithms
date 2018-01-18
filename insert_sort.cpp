//
// Created by manout on 18-1-18.
//

#include <vector>
#include <algorithm>

using std::upper_bound;
using std::lower_bound;
using std::vector;

void insert_sort(vector<int>& data)
{
	for (auto it = data.begin() + 1; it not_eq data.end(); ++it)
	{
		auto const insertion_point = std::upper_bound(data.begin(), it, *it);
		std::rotate(insertion_point, it, it+1);
	}
}
