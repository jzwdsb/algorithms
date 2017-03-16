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
 *	�Ƴ�������˳������ظ�Ԫ��
 *	������
 *			����һ��������˳�������ȥ���ظ���Ԫ���ǵ�ÿ��Ԫ��ֻ����һ�β��ҷ��ظ�˳�����³���
 *			�����������µĿռ���Ϊ������;�������ʹ�ó������ڴ�ռ�
 *			ʾ��,��������˳��� A [1, 1, 2]
 *			��ĺ���Ӧ�÷��س���2����A������[1, 2]
 *			
 */

//�Լ��ֶ�ʵ�֣�ԭ���
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


//  ʹ��STL��Ϊ�򵥣�distance��������������֮��ľ��룬unique�����������е��ظ�Ԫ���ƶ���β��
//	�����ز��ظ�Ԫ�ص�β�������
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