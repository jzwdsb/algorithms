#include "all_include.h"

using std::queue;

void merge(int array [], int begin, int middle, int end)
{
	//auto leftLength = middle - begin ;
	//auto rightLength = end - middle;

	queue<int > leftArray;
	queue<int > rightArray;
	
	auto i = begin, j = middle;

	for (; i < middle; ++i)
		leftArray.push(array[i]);
	for (; j < end; ++j)
		rightArray.push(array[j]);

	auto k = begin;
	for (; k < end; ++k)
	{
		if ( leftArray.size() && rightArray.size())
		{
			if (leftArray.front() < rightArray.front())
			{
				array[k] = leftArray.front();
				leftArray.pop();

			}

			else if (rightArray.front() < leftArray.front())
			{
				array[k] = rightArray.front();
				rightArray.pop();
			}
			else
			{
				array[k] = leftArray.front();
				array[k + 1] = rightArray.front();
				leftArray.pop(); rightArray.pop();
			}

		}
		else break;	
	}
	if (leftArray.size())
	{
		while (leftArray.size())
		{
			array[k] = leftArray.front();
			leftArray.pop();
			++k;
		}
	}
	if (rightArray.size())
	{
		while (rightArray.size())
		{
			array[k] = rightArray.front();
			rightArray.pop();
			++k;
		}
	}

}

void mergeSort(int array[], int begin, int end)
{
	if (end - begin > 1)
	{	
		auto middle = (end + begin) / 2;
		mergeSort(array, begin, middle);
		mergeSort(array, middle, end);

		merge(array, begin, middle, end);
		
	
	}
}