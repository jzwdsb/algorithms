#include "stdafx.h"
using std::vector;
typedef vector<int> inputType;

/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand
 * (i, e, 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).
 * you are given a target valur to search. if found in the array return its index, otherwise return -1.
 * you may assume no duplicates exists in the array.
 * 
 * �������һ���������˳�����ĳһ��λ���Ǿ�����ת��
 * ����(0 1 2 4 5 6 7) ������ ( 4 5 6 7 0 1 2)
 * ��Ҫ�ڸ�˳���������һ��������Ŀ��ֵ������ҵ��򷵻����±�
 * ���򷵻�-1.
 * �������Ϊ��˳����в������ظ���Ԫ��
 *
 *
 * ������
 *		��ֱ�۵�д����˳�����η��ʣ����Ǵ������ٵķ���
 *		ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1)
 *		���ǵ���ǳ���ʱ���������Ч�ʷǳ���
 *		�������Ǹ����������˳���
 *		����ʹ�ö��ַ����ѵ��������±߽��ȷ��
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

		//��С���������Ӧ��������������������˵����м�Ĺ�ϵ
		
		//������С���м�ֵ��˵�� first -- last �У��ϴ����䳤�Ȳ�����һ��
		//��ô������ˣ��м�ֵ��Ŀ��ֵ�Ĺ�ϵ��С��Χ
		if(nums[first] <= nums[middle])
		{
			//������С��Ŀ��ֵ���м�ֵ����Ŀ��ֵ����Ӧ�ð�������Χ��С��ֵ��벿��
			if(nums[first] <= target and nums[middle] > target)
			{
				last = middle;
			}

			//����Ӧ�ý�������Χ��С���Ұ벿�ݣ���벿���ж�����middle
			else
			{
				first = middle + 1;
			}
		}
		
		//��ǰС����ĳ��Ȳ�����һ��
		else
		{
			//������ֵ����Ŀ��ֵ���м�ֵС��Ŀ��ֵ����Ӧ�ð�������Χ��С���Ұ벿��
			if(nums[first] > target and nums[middle] < target)
			{
				first = middle + 1;
			}
			//����Ӧ�ð�������Χ��С����벿��
			else
			{
				last = middle;
			}
		}
	}

	//  δ���������������-1
	return -1;
}