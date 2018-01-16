//
// Created by manout on 18-1-16.
//

#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

pair<int, vector<int>> Areas_on_the_cross_section_diagram(const string& line)
{
	int sum = 0;
	vector<int> ans;
	stack<int> s1;
	stack<pair<int, int>> s2;
	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i] == '\\')
		{
			s1.push(i);
		}else if (line[i] == '/' and not s1.empty())
		{
			int j = s1.top(); s1.pop();
			/** a 是当前面积*/
			int a = i - j;
			sum += a;
			while( not s2.empty() and s2.top().first > j)
			{
				a += s2.top().second;
				s2.pop();
			}
			s2.push(make_pair(j ,a));
		}
	}
	while (not s2.empty())
	{
		ans.push_back(s2.top().second);
		s2.pop();
	}
	reverse(ans.begin(), ans.end());
	return make_pair(sum, ans);
}

