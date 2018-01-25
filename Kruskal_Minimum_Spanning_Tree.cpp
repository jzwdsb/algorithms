#include "all_include.h"
#include "DisJointSet.h"
#include "Minimum_Spanning_Tree.h"
using std::vector;
using std::pair;
using std::queue;


//�Ժ�����Ż�
// 11/30�޸ģ�����ֵ��ΪMinimum_Spanning_Tree����
MST kruskal(size_t vertex_count,vector<Edge> source)
{
	DisJointSet dis_set(vertex_count);
	sort(source.begin(), source.end());

	auto toltal_distance = 0;
	auto it = source.begin();
	Edge_collect minSpaning;
	do
	{
		auto edge = *it;
		
		if (dis_set.isSameSet(edge.source,edge.target))
		{
			dis_set.unite_Set(edge.source, edge.target);
			minSpaning.push_back(*it);
		}
		++it;
	} while (dis_set.count_set() > 1 and it != source.end());
	
	
	return minSpaning;
}