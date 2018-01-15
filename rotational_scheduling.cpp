//
// Created by manout on 18-1-14.
//

#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using std::vector;
using std::string;
using std::queue;
using std::min;

struct procInfo
{
	string name;
	int time;
};

/** 	assume the input data is in a squence form
 * first we scan the sequence and push the job into
 * a queue which can't finish in a time slice.
 * 		then do as the rotational algorithms until the
 * 	queue is empty.
 * */
vector<procInfo> rotational_scheduling(const int timelimit, const vector<procInfo>& sequence)
{
	int endtime = 0;
	int c;
	queue<procInfo> q;
	vector<procInfo> finishedProc;
	for (auto it = sequence.begin(); it not_eq sequence.end(); ++it)
	{
		c = min(it->time, timelimit);
		endtime += c;
		if (it->time > c)
		{
			q.emplace(it->name, it->time - c);
		}else
		{
			finishedProc.emplace_back(it->name, endtime);
		}
		
	}
	while (not q.empty())
	{
		procInfo p = q.front();
		c = min(p.time, timelimit);
		endtime += c;
		if (p.time > c)
		{
			q.emplace(p.name, p.time - c);
		}else
		{
			finishedProc.emplace_back(p.name, endtime);
		}
	}
	return finishedProc;
}