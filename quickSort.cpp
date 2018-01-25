#include "all_include.h"
int partition(int array[], int begin, int end);

void quickSort(int array[], int begin, int end)
{
	if (begin < end)
	{
		auto middle = partition(array, begin, end);
		quickSort(array, begin, middle);
		quickSort(array, middle + 1, end);

	}
}


int partition(int array[], int begin, int end)
{
	auto flag = array[end - 1];
	auto mark = begin - 1;
	for (auto i = begin; i < end - 1; ++i)
		if (array[i] <= flag)
		{
			++mark;
			if (mark != i)
				std::swap(array[i], array[mark]);
			
		}
	

	std::swap(array[mark + 1], array[end - 1]);
	return mark + 1;
}