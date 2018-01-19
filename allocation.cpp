//
// Created by manout on 18-1-19.
//

#include <vector>
#include <algorithm>


using std::vector;

using std::max;

static int n;
static int k;

static vector<int> data;

int check(int P)
{
	int i = 0;
	for (int j = 0; j < data.size(); ++j)
	{
		int s = 0;
		while (s +data[i] <= P)
		{
			++i;
			s += data[i];
			if (i == n)return n;
		}
	}
	return i;
}



int allocation()
{
	int left = 0;
	int right = n * *max(data.begin(), data.end());
	while (right - left > 1)
	{
		int mid = (left + right) / 2;
		int v = check(mid);
		if (v >= n) right = mid;
		else left = mid;
	}
	return right;
}
