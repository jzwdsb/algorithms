#include "stdafx.h"
using std::vector;
typedef vector<int> inputType;

/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand
 * (i, e, 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).
 * you are given a target valur to search. if found in the array return its index, otherwise return -1.
 * you may assume no duplicates exists in the array.
 * 
 * 假设存在一个已排序的顺序表在某一个位置是经过旋转的
 * 比如(0 1 2 4 5 6 7) 可能是 ( 4 5 6 7 0 1 2)
 * 你要在该顺序表中搜索一个给定的目标值，如果找到则返回其下标
 * 否则返回-1.
 * 你可以认为在顺序表中不存在重复的元素
 *
 *
 * 分析：
 *		最直观的写法是顺序依次访问，这是代码最少的方法
 *		时间复杂度 O(n)，空间复杂度 O(1)
 *		但是当表非常长时，这个方法效率非常低
 *		由于这是个大致有序的顺序表
 *		可以使用二分法，难点在于上下边界的确认
 */



int search_simple(inputType nums, int target)
{
	for(int it = 0; it < nums.size(); ++it)
	{
		if(nums[it] == target)
		{
			return it;
		}
	}
	return -1;
}


int binary_search_rotated_array(inputType nums, int target)
{
	int first = 0, last = nums.size();
	while(first != last)
	{
		const int middle = (first + last) / 2;
		if(nums[middle] == target)
		{
			return middle;
		}

		//缩小区间的条件应该是搜索区间的左右两端的与中间的关系
		
		//如果左端小于中间值，说明 first -- last 中，较大区间长度不少于一半
		//那么根据左端，中间值和目标值的关系缩小范围
		if(nums[first] <= nums[middle])
		{
			//如果左端小于目标值且中间值大于目标值，则应该把搜索范围缩小至值左半部分
			if(nums[first] <= target and nums[middle] > target)
			{
				last = middle;
			}

			//否则应该将搜索范围缩小至右半部份，左半部分中都大于middle
			else
			{
				first = middle + 1;
			}
		}
		
		//当前小区间的长度不少于一半
		else
		{
			//如果左端值大于目标值且中间值小于目标值，则应该把搜索范围缩小至右半部份
			if(nums[first] > target and nums[middle] < target)
			{
				first = middle + 1;
			}
			//否则应该把搜索范围缩小至左半部分
			else
			{
				last = middle;
			}
		}
	}

	//  未搜索到结果，返回-1
	return -1;
}