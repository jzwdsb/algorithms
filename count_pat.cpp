//
// Created by manout on 17-9-4.
//

#include <string>
#include <cstddef>
#include <algorithm>

using std::string;
using std::count;
size_t count_pat(const string& pat)
{
	size_t ret = 0;
	for (string::const_iterator it = pat.begin(); it not_eq pat.end(); ++it)
	{
		if(*it == 'P')
		{
			for (string::const_iterator it_a = it + 1; it not_eq pat.end(); ++it_a)
			{
				if(*it_a == 'A')
				{
					ret += count(it_a + 1, pat.end(); 'T');
				}
			}
		}
	}
	return ret;
}


