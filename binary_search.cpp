//
// Created by manout on 18-1-17.
//

#include <vector>
#include <algorithm>

using std::lower_bound;
using std::vector;

/** the input S is ensured is in ordered*/

bool bin_search_r(vector<int> &S, int low, int high, int key)
{
	if (low >= high)
		return false;
	int i = (low + high) / 2;
	if (S[i] == key)
		return true;
	if (S[i] > key)
	{
		return bin_search_r(S, low, i, key);
	}
	else return bin_search_r(S, i, high, key);
	
}

bool bin_search(vector<int>& S, int key)
{
	int left = 0;
	int right = static_cast<int>(S.size());
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (S[mid] == key)
			return true;
		if (S[mid] > key)
			right = mid;
		else left = mid;
	}
	return false;
}

int binary_search(int n, vector<int>& S, int q, vector<int>& T)
{
	int count = 0;
	S.push_back(0);
	for (int ele : T)
	{
		if (*lower_bound(S.begin(), S.end(), ele) == ele)
		{
			++count;
		}
	}
	return count;
}