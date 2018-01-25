#include "all_include.h"
#include "HuffmanTreeTable.h"


void HuffmanTreeTable:: makeTree(const std::vector<Node> &inputData)
{
	this->leafCounts = inputData.size();
	std::vector<std::pair<Node, size_t>> sortedData;
	std::vector<std::pair<Node, size_t>> resultBefore;
	for (size_t i = 0; i < inputData.size(); ++i)
		sortedData.push_back(std::make_pair(inputData[i], i));

	auto i = sortedData.size();
	while (sortedData.size() > 1)
	{
		std::sort(sortedData.begin(), sortedData.end(),
			//添加谓词，按每个节点权重排序
			[](const std::pair<Node, size_t> &a, const std::pair<Node, size_t> &b)
				{return a.first.weight < b.first.weight; });
		auto a_min = sortedData[0];
		auto b_min = sortedData[1];
		sortedData.erase(sortedData.begin());
		sortedData.erase(sortedData.begin());
		auto newNode = std::make_pair(Node(a_min.first.weight + b_min.first.weight), i);
		newNode.first.lChild = a_min.second;
		newNode.first.rchild = b_min.second;
		sortedData.push_back(newNode);
		a_min.first.parrent = i;
		b_min.first.parrent = i;
		resultBefore.push_back(a_min);
		resultBefore.push_back(b_min);
		resultBefore.push_back(newNode);
		++i;
	}
	std::sort(resultBefore.begin(), resultBefore.end(),
		//添加谓词，按原先在数据和创建的顺序排序
		[](const std::pair<Node, size_t> &a, const std::pair<Node, size_t> &b)
			{return a.second < b.second; });

	for (auto it = resultBefore.begin(); it != resultBefore.end(); ++it)
		this->HuffmanTable.push_back((*it).first);

	this->tableLength = HuffmanTable.size();
	
}

void HuffmanTreeTable::clearAllData()
{
	leafCounts = 0;
	tableLength = 0;
	HuffmanTable.clear();
}
