//
// Created by manout on 17-9-27.
//

#include "common_use.h"


int number_grid(const int N)
{
	for (int a3 = N; a3 >= 0; --a3)
	{
		for (int a2 = a3; a2 >= 0 --a2)
		{
			for (int a1 = a2; a1 >= 0; --a1)
			{
				if ((a1 + a2 + a3) % 5 == 0)
				{
					if ((a2 + a3) % 3 == 0)
					{
						if ((a1 + a2) % 2 == 0)
						{
							return a1 + a2 + a1;
						}
					}
				}
			}
		}
	}
}
