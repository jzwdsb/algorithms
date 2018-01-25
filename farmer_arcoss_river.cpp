// farmer_arcoss_river.cpp : 定义控制台应用程序的入口点。
//

#include "all_include.h"
#include <stdlib.h>
#define MAX_VERTEX 20
#define and			&&
#define not			!
#define not_eq		!=
#define or			||
#define is_eq	    ==

//顶点类型，当某一位为一时代表存在该物，零表示不存在该物
struct vertex
{
	int Human;
	int Wolf;
	int Sheep;
	int Cabbage;
	vertex() :Human(0), Wolf(0), Sheep(0), Cabbage(0) {}
	vertex(int H, int W, int S, int C) :Human(H), Wolf(W), Sheep(S), Cabbage(C) {}
};

//顶点计数
static  size_t ver_count = 0;
//顶点集合
static 	vertex vertex_collect[MAX_VERTEX];
//邻接矩阵 edge[u][v] == 1 表示vertex[u]和vertex[v]之间存在一条边
static  int edge[MAX_VERTEX][MAX_VERTEX];
//生成路径 path[u] == v 表示 应该从 u 节点访问到 v 节点
static int path[MAX_VERTEX];
//标志，flag[u] 表示 u 节点是否已经被访问
bool flag[MAX_VERTEX];
void init_graph();
void generate_path();
void print_graph();
void print_matrix();
void print_path();

int main()
{
	init_graph();
	printf_s("\n-------------------------深度优先方法实现农夫过河算法-------------------\n\n");
	printf_s("\t农夫带着狼，羊和白菜来到了河岸，他想带着他的宠物全部过去，可是他的小船同时之能带他自己和狼，羊和白菜中的一个\n((#｀皿´)鬼知道那个白菜有多沉),\n");
	printf_s("但是如果没有农夫看着，羊会把白菜吃掉，狼会把羊吃掉(o(*≧д≦)o!!好可怕),该怎么办\n");
	printf_s("一直觉得自己很机智的农夫一直在想在怎么办呢\n");
	for (int i =0; i < 5; ++i)
	{
		printf_s("……\n");
		Sleep(1000);
	}
	printf_s("机智的农夫经过五秒想出了答案(没错，不多不少正好五秒)，他将此岸所有可以安全存在的状态变成一个图的顶点，在可以只经过一步转换从一个顶点到另一个顶点");
	printf_s("之间添加一条边，从起始状态出发，到达此岸为空的状态所经历的点连接起来，就可以过去了，想到这里他不禁为自己点了个赞\n ＼(*T▽T*)／ \n");
	system("pause");
	printf_s("下面是他得出的安全状态\n");
	print_graph();
	
	system("pause");
	printf_s("下面是上面顶点的连接关系:\n");
	print_matrix();

	generate_path();
	system("pause");
	printf_s("农夫开始带着狼，羊和白菜过河了：\n以下是此岸的变化\n");
	print_path();
	printf_s("欢呼！！！o((*^▽^*))o o((*^▽^*))o o((*^▽^*))o o((*^▽^*))o o((*^▽^*))o o((*^▽^*))o\n");
	fflush(stdin);
	getchar();
    return 0;
}

//打印顶点
void print_vertex(vertex ver)
{
	if (ver.Human or ver.Wolf or ver.Sheep or ver.Cabbage)
		printf_s("%s\t%s\t%s\t%s\t", ver.Human ? "人" : " ", ver.Wolf ? "狼" : " ", ver.Sheep ? "羊" : " ", ver.Cabbage ? "菜" : " ");
	else
		printf_s("人和货物都到了对岸\t");
}

//打印顶点集
void print_graph()
{
	for (size_t i = 0; i< ver_count; ++i)
	{
		printf_s("%d 号顶点： ", i + 1);
		print_vertex(vertex_collect[i]);
		printf_s("\n");
	}
	printf_s("\n");
}

//打印邻接矩阵
void print_matrix()
{
	for (size_t i = 0; i < ver_count; ++i)
	{
		printf_s("%d 号顶点的邻接矩阵: \t", i + 1);
		for (size_t j = 0; j < ver_count; ++j)
		{
			printf_s("%d\t", edge[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");
}

//打印动作
void print_move(int prev, int curr)
{
	if(prev is_eq curr)
	{
		printf_s("农夫和他的小动物们出发了(*￣︶￣)");
	}
	else 
	{
		if(vertex_collect[prev].Wolf  > vertex_collect[curr].Wolf)
		{
			printf_s("农夫带着狼过河了((((;°Д°))))");
		}
		else if(vertex_collect[prev].Wolf < vertex_collect[curr].Wolf)
		{
			printf_s("农夫带着狼回来了∑(O_O；)");
		}
		if(vertex_collect[prev].Sheep > vertex_collect[curr].Sheep)
		{
			printf_s("农夫带着羊过河了ヾ(@^▽^@)ノ");
		}
		else if (vertex_collect[prev].Sheep < vertex_collect[curr].Sheep)
		{
			printf_s("农夫带着羊回来了ヾ(*>∀＜*)");
		}
		if (vertex_collect[prev].Cabbage > vertex_collect[curr].Cabbage)
		{
			printf_s("农夫带着白菜过河了(￣▽￣)~*");
		}
		else if(vertex_collect[prev].Cabbage < vertex_collect[curr].Cabbage)
		{
			printf_s("农夫带着白菜回来了(ｖ＾＿＾)ｖ");
		}
		if (vertex_collect[prev].Wolf is_eq vertex_collect[curr].Wolf and vertex_collect[prev].Sheep is_eq vertex_collect[curr].Sheep and vertex_collect[prev].Cabbage is_eq vertex_collect[curr].Cabbage)
		{
			if(vertex_collect[prev].Human > vertex_collect[curr].Human)
			{
				printf_s("农夫独自过了河(`皿´)");
			}
			else
			{
				printf_s("农夫独自回来了<(｀^´)>");
			}
		}
	}
	
}

//打印路径
void print_path()
{
	int s = 0;
	int prev = s;
	while (s not_eq ver_count - 1 and s not_eq -1)
	{
		print_vertex(vertex_collect[s]);
		print_move(prev, s);
		prev = s;
		s = path[s];
		printf_s("\n");
		Sleep(2000);
	}
	print_vertex(vertex_collect[ver_count - 1]);
	printf_s("\n");
}

//判断当前状态是否安全，羊和人不在一起时，狼和羊在一起或羊和羊和白菜在一起是不安全的
bool is_safe(int H, int W, int S, int C)
{
	if (H not_eq S and (W is_eq S or S is_eq C))
		return false;
	return true;
}

bool is_one_step(vertex, vertex);
void generate_edge();

//初始化图的点集和邻接矩阵
void init_graph()
{
	for (int H = 1 ; H >= 0; --H)
		for (int W = 1; W >= 0  ; --W)
			for(int S = 1; S >= 0; --S)
				for(int C = 1; C >= 0; --C)
				{
					if (is_safe(H, W, S, C))
						vertex_collect[ver_count++] = vertex(H, W, S, C);
				}
	for (size_t i = 0; i < ver_count; ++i)
		flag[i] = false;
	generate_edge();
}

//状态转移函数，判断两个顶点是否存在一条边，判断条件是两状态农夫位不同，其他位只有一位不同
bool is_one_step(vertex a, vertex b)
{
	if (a.Human is_eq b.Human)
		return false;
	if (a.Wolf not_eq b.Wolf and a.Sheep is_eq b.Sheep and a.Cabbage is_eq b.Cabbage)
		return true;
	if (a.Sheep not_eq b.Sheep and a.Wolf is_eq b.Wolf and a.Cabbage is_eq b.Cabbage)
		return true;
	if (a.Cabbage not_eq b.Cabbage and a.Wolf is_eq b.Wolf and a.Sheep is_eq b.Sheep)
		return true;
	if (a.Wolf is_eq b.Wolf and a.Sheep is_eq b.Sheep and a.Cabbage is_eq a.Cabbage)
		return true;
	return false;
}

//生成邻接矩阵
void generate_edge()
{

	for (size_t i = 0; i < ver_count; ++i)
		for (size_t j = 0; j < ver_count; ++j)
			edge[i][j] = 0;
	for (size_t i =0; i < ver_count;++i)
	{
		for (size_t j = 0; j < ver_count; ++j)
		{
			if (is_one_step(vertex_collect[i], vertex_collect[j]))
				edge[i][j] = 1;
		}
	}
}

//找到邻接矩阵中 i 号节点所相连的第一条边
int find_path(int u)
{
	for (size_t i = 0; i < ver_count; ++i)
		if (edge[u][i] and not flag[i])
			return i;
	//当前节点无
	return -1;
}

//生成路径，信息保存在 path 数组中
void generate_path()
{
	int start = 0;
	flag[start] = true;
	int prev = start;
	stack<int> s;
	while (start not_eq ver_count - 1 and start not_eq -1)
	{
		start = find_path(start);
		if (start not_eq -1 and start not_eq prev)
		{
			path[prev] = start;
			flag[start] = true;
			prev = start;
			s.push(start);
		}
		else
		{
			start = s.top();
			s.pop();
			prev = start;
		}
	}
}