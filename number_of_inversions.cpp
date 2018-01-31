//
// Created by manout on 18-1-25.
//

#include "common_use.h"

#define SENTINEL  2000000000

using llong = long long;


llong merge_sort(vector<int>& a, int low, int mid, int high)
{
	int i = 0, j = 0, k;
	llong cnt = 0;
	vector<int> left(a.begin() + low, a.begin() + mid);
	vector<int> right(a.begin() + mid, a.begin() + high);
	for (k = low; k < high and i < left.size() and j < right.size(); ++k)
	{
		if (left[i] <= right[j])
		{
			a[k] = left[i];
			++i;
		}else
		{
			a[k] = right[j];
			++j;
			cnt += left.size() - i;
		}
	}
	while (i < left.size())
	{
		a[k] = left[i];
		++k;
		++i;
	}
	while (j < right.size())
	{
		a[k] = right[j];
		++k;
		++j;
	}
	return cnt;
	
}


llong count_inversions(vector<int>& data, int low, int high)
{
	llong v1, v2, v3;
	int mid = (low + high) / 2;
	if (low + 1 < high)
	{
		v1 = count_inversions(data, low, mid);
		v2 = count_inversions(data, mid, high);
		v3 = merge_sort(data, low, mid, high);
		return v1 + v2 + v3;
	}
	return 0;
}