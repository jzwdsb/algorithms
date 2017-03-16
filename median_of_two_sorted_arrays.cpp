#include"stdafx.h"
using std::vector;


/*
 * There are two sorted arrays A and B of size and n respectivelt.
 * Find the median of the two sorted arrays. The overall run time
 * should be O(log(m + n))
 * 
 * 有两个长度不同已排序的数组 A 和 B，找到这两者的所有元素的中间值。
 * 时间复杂度的上限应该是 O(log(m + n))
 * 
 * 
 * 
 * 
 */


//最直观的写法，时间复杂度 O( m + n )，空间复杂度 O( m + n)
int search_median_simple(vector<int> &a, vector<int> &b)
{
	int mid = (a.size() + b.size()) / 2;
	vector<int>::iterator ita = a.begin(), itb = b.begin();
	vector<int> c;

	while(ita not_eq a.end() and itb not_eq b.end())
	{
		if (*ita < *itb)
		{
			c.push_back(*ita);
		}
		else
		{
			c.push_back(*itb);
		}
	}
	if (ita not_eq a.end())
	{
		while(ita not_eq a.end())
		{
			c.push_back(*ita);
			++ita;
		}
	}
	else if(itb not_eq b.end())
	{
		while(itb not_eq b.end())
		{
			c.push_back(*itb);
			++itb;
		}
	}

	return c[mid];
}