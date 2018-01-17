//
// Created by manout on 18-1-17.
//

#include <vector>

using std::vector;


/** After the flag at the end of the array, the compare operate reduce to one time
 * the time complexity is not reduced, but it can a constant acceleration.
 * */
bool search(int n, vector<int>& S, int ele)
{
	S[n] = ele;
	int i = 0;
	while (S[i] not_eq ele)
	{
		++i;
	}
	return i != n;
}

int linear_search(int n, vector<int>& S, int q, vector<int>& T)
{
	int count = 0;
	S.push_back(0);
	for (int ele : T)
	{
		if (search(n, S, ele))
		{
			++count;
		}
	}
	return count;
}
