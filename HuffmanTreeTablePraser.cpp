#include "HuffmanTreeTablePraser.h"

void HuffmanTreeTablePraser::boundTo(HuffmanTreeTable& source)
{
	
	dataSourcePtr = &source.HuffmanTable;
	begofSource = source.begin();
	endofSource = source.begin() + source.leafCounts;
}

void HuffmanTreeTablePraser::praseTree() 
{
	for (auto itor = begofSource; itor != endofSource; ++itor)
	{
		
		std::stack<char> revStr;
		size_t parrentIndex = itor->parrent;
		size_t selfIndex = itor - begofSource;
		Node currentNode;
		do
		{
			currentNode = (*dataSourcePtr)[parrentIndex];
			if (selfIndex == currentNode.lChild)
				revStr.push('0');

			else if (selfIndex == currentNode.rchild)
				revStr.push('1');
			
			else throw std::invalid_argument("table message is wrong");
			selfIndex = parrentIndex;
			parrentIndex = currentNode.parrent;
		}while (parrentIndex not_eq 0);
		
		std::string oneResult;
		do
		{
			oneResult.push_back(revStr.top());
			revStr.pop();
		}
		while (not revStr.empty());
		praserResult.push_back(oneResult);
	}
}

std::string decodingTree(std::vector<Node> &tree)
{
	std::stack<std::string> revstring;
	std::string result;
	//auto table = (tree.size() + 1) / 2;
	Node data = tree.front();
	size_t index = data.parrent;
	size_t selfIndex = 0;
	do
	{
		data = tree[index];
		if (selfIndex == data.lChild)
			revstring.push(std::string("0"));
		else if (selfIndex == data.rchild)
			revstring.push(std::string("1"));
		else throw std::invalid_argument("wrong input");

		selfIndex = index;
		index = data.parrent;
	} while (data.parrent != 0);

	do
	{
		result.append(revstring.top());
		revstring.pop();
	} while (not revstring.empty());

	return result;
}
