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
	//���캯��ֻʵ����Ĭ�Ϲ��캯���Ϳ������캯��������շ������Ĺ���ί�и���һ����Ա����
	HuffmanTreeTable() {}
	HuffmanTreeTable(const HuffmanTreeTable &r_table) :
		leafCounts(r_table.leafCounts), tableLength(r_table.tableLength) , HuffmanTable(r_table.HuffmanTable) {}
	//�������ֶ�����Ķ��ڴ�������������Ϊ�գ��ڴ�Ļ��ս���STL��������
	~HuffmanTreeTable() {}
	
	void makeTree(const vector<Node> &data);
	void clearAllData();

	//���غշ�����ĵ��������ɵ��������ΪҶ�ӽڵ�
	auto begin()const ->vector<Node>::const_iterator { return HuffmanTable.cbegin(); }
	vector<Node>::const_iterator end() { return HuffmanTable.cbegin() + leafCounts; }
	
private:
	size_t leafCounts = 0;
	size_t tableLength = 0;
	vector<Node> HuffmanTable;
};

