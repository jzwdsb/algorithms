#include "stdafx.h"
using std::vector;

/*
 *	Follow up for "remove duplicate from sorted array":what if duplicates are allowed at most twice
 *	for example, given sorted array A = [1, 1, 1 ,2, 2, 3], your funtion should return length = 5, and A is
 *	now [1, 1, 2, 2, 3] .
 *	紧接着 “移除已排序顺序表中重复元素”： 如果元素最多允许重复两次呢？
 *	举个例子，一个给定已排序的顺序表 A = [1, 1, 1 ,2, 2, 3]， 你的函数应该返回长度等于5， 并且此时A = [1, 1, 2, 2, 3]
 *	分析：
 *		由于该顺序表是有序的，所以要顺序遍历用一个辅助变量计数即可
 *		
 *		
 */

int remove_duplicates2_self(vector<int> &nums)
{
	if (nums.size() <= 2)
	{
		return nums.size();
	}
	
	//常规思维的方法删除中多余的元素不可行，因为删除会改变表的长度，引用时易发生违规内存访问

	return nums.size();
}


int remove_duplicates2(vector<int> &nums)
 {
	 if (nums.size() <= 2)
	 {
		 return nums.size();
	 }
	 int index = 2;				//此时nums长度一定大于2，取index为2

	 //设初始符合结果的表长为index，初始为2，元素下标为2及2之后的元素
 	 //为向表后添加使得nums的前index个元素仍符合结果要求
	 for(int i = 2; i < nums.size(); ++i)
	 {
		 //从第三个开始向后遍历
		 if (nums[i] not_eq nums[i - 2])
		 {
			 //如果第 i 个元素等于第 i - 2 个元素，那么这个元素不可以向输出表后添加直接跳过
			 //则index不变
			 //当第 i 个元素不等于第 i - 2 个元素，那么这个元素就可以向输出表后添加，
		 	 //那么index + 1
			 nums[index++] = nums[i];
		 }
	 }
	 //当循环结束时，index的值为输出表元素的个数
	 return index;
 }

int remove_duplicates2_(vector<int> &nums)
{
	int n = nums.size();
	int index = 0;			//设初始输出表长为0
	for (int i = 0; i < n; ++i)
	{
		//当第 i 个元素等于第 i - 1 且等于第 i + 1 个元素时，认为表长是无需变化的
		//第 i 个元素无需添加到表 index后面
		if (i > 0 and i < n - 1 and nums[i] == nums[i - 1] and nums[i] == nums[i + 1])
			continue;

		//如果上述条件有一个不符合，则第 i 个元素应该添加到index后
		nums[index++] = nums[i];
	}

	return index;
}
