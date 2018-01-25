#include "all_include.h"
#include "Minimum_Spanning_Tree.h"
#include <random>



Edge_collect generate_edge_collect(size_t ver_count, size_t edge_count)
{
	srand(unsigned(_get_current_locale()));
	Edge_collect edges;
	
	vector<weak_eage> ed_mult;
	do
	{
		int lver = rand() % ver_count;
		int rver = rand() % ver_count;
		weak_eage temp_eage(lver, rver);		
		if (lver not_eq rver)
		{
			if (find(ed_mult.begin(), ed_mult.end(),temp_eage) == ed_mult.end())
			{
				int weight = rand() % 1000;
				while (not weight)
				{
					weight = rand() % 1000;
				}
				ed_mult.push_back(temp_eage);
				edges.push_back(Edge(temp_eage, weight));
			}	
		}
	}while (edges.size() < edge_count);
	return edges;
}


