#include "stdafx.h"
#include <algorithm>

using std::vector;


/*
 *	Remove duplicates from sorted array
 *	description;
 *			Given a sorted array, remove the duplicates in place such that each element appear only once
 *		and return the new length.
 *			Do not allocate extra space for another way,you must do this with constant memory.
 *			For example, Given input array A = [1, 1, 2]
 *			your funtion should return length is 2, and A is now [1, 2].
 *	移除已排序顺序表中重复元素
 *	描述：
 *			给定一个已排序顺序表，从中去除重复的元素是的每个元素只出现一次并且返回该顺序表的新长度
 *			不允许申请新的空间作为其他用途，你必须使用常量的内存空间
 *			示例,给定输入顺序表 A [1, 1, 2]
 *			你的函数应该返回长度2并且A现在是[1, 2]
 *			
 */

//自己手动实现，原理简单
int remove_duplicates(vector<int>  &input)
{

	vector<int>::iterator front = input.begin();
	vector<int>::iterator next = front + 1;
	while (next not_eq input.end() and front not_eq input.end())
	{
		if(*front == *next)
		{
			input.erase(next);
		}

		++next, ++front;
	}

	return input.size();
}


//  使用STL最为简单，distance返回两个迭代器之间的距离，unique将排序容器中的重复元素移动到尾部
//	并返回不重复元素的尾后迭代器
int remove_duplicates_stl(vector<int> &input)
{
	return std::distance(input.begin(), std::unique(input.begin(), input.end()));

}



template<typename InIt, typename OutIt>
OutIt removeDupliates(InIt first, OutIt last, OutIt output)
{
	while(first not_eq last)
	{
		*output++ = *first;
		first = std::upper_bound(first, last, *first);
	} 
	return output;
}

int remove_duplicates_stl_(vector<int> &input)
{
	return std::distance(input.begin(), removeDupliates(input.begin(), input.end(), input.begin()));
}