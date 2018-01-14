//
// Created by manout on 18-1-14.
//

#include <queue>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::queue;

struct procInfo
{
	string name;
	int time;
};

vector<procInfo> rotational_scheduling(const int timelimit, const vector<procInfo>& sequence)
{
	int endtime = 0;
	queue<procInfo> q;
	vector<procInfo> ret;
	for (auto it = sequence.begin(); it not_eq sequence.end(); ++it)
	{
		if(it->time > timelimit)
		{
			q.emplace(it->name, it->time - timelimit);
			endtime += it->time -timelimit;
		}
		else
		{
			endtime += it->time;
			ret.emplace_back(it->name, endtime);
		}
	}
}