#pragma once

#include "all_include.h"
#include "HuffmanTreeTablePraser.h"
struct Node
{
	int weight;
	int parrent;
	int lChild;
	int rchild;
	Node() :weight(0), parrent(0), lChild(0), rchild(0) {}
	Node(int wt) :weight(wt), parrent(0), lChild(0), rchild(0) {}
	bool operator <(Node &b_node)const { return this->weight < b_node.weight; }
};

class HuffmanTreeTable
{
friend class HuffmanTreeTablePraser;
public:
	//构造函数只实现了默认构造函数和拷贝构造函数，构造赫夫曼树的过程委托给另一个成员函数
	HuffmanTreeTable() {}
	HuffmanTreeTable(const HuffmanTreeTable &r_table) :
		leafCounts(r_table.leafCounts), tableLength(r_table.tableLength) , HuffmanTable(r_table.HuffmanTable) {}
	//不存在手动分配的堆内存所以析构函数为空，内存的回收交给STL容器进行
	~HuffmanTreeTable() {}
	
	void makeTree(const vector<Node> &data);
	void clearAllData();

	//返回赫夫曼表的迭代器，可迭代区间仅为叶子节点
	auto begin()const ->vector<Node>::const_iterator { return HuffmanTable.cbegin(); }
	vector<Node>::const_iterator end() { return HuffmanTable.cbegin() + leafCounts; }
	
private:
	size_t leafCounts = 0;
	size_t tableLength = 0;
	vector<Node> HuffmanTable;
};

