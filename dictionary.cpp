//
// Created by manout on 18-1-19.
//

#include <vector>
#include <string>
#include <set>

using std::vector;
using std::string;
using std::pair;
using std::set;

/** Write a program of a simple dictionary which implements the following instructions
 * 		1: insert str. insert a string into a dictionary
 * 		2: find str. if the dictionary contains str, then print 'yes', otherwise print 'no'
 * */

vector<string> dictionaay(const vector<pair<string, string>>& input)
{
	vector<string> ans;
	set<string> container;
	for (const pair<string, string>& ins : input)
	{
		if (ins.first[0] == 'i')
		{
			container.insert(ins.second);
		}else
		{
			ans.emplace_back(container.count(ins.second) == 1 ? "yes" : "no");
		}
	}
	return ans;
}
