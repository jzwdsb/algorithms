#pragma once

#include "all_include.h"
#include "HuffmanTreeTable.h"
#include <memory>
// ����˳��δ֪���Լ�ʹ����HuffmanTreeTableͷ�ļ����п�������֮ǰ���룬����Ҫ���϶�HuffmanTreeTabl��ĳ�ǰ����
 struct Node;
 class HuffmanTreeTable;

class HuffmanTreeTablePraser
{
public:
	HuffmanTreeTablePraser() :begofSource(),endofSource(),dataSourcePtr(nullptr) {}
	~HuffmanTreeTablePraser() {  }

	void boundTo( HuffmanTreeTable &source);
	void praseTree() ;
	std::string getPraseResultAtIndex(size_t index) { return praserResult[index]; }
	std::vector<std::string> getPraseResult() const { return praserResult; }
	void clear() { begofSource = std::vector<Node>::iterator(); endofSource = begofSource; 
					dataSourcePtr = nullptr; praserResult.clear(); }
private:
	std::vector<Node>::const_iterator begofSource;
	std::vector<Node>::const_iterator endofSource;
	std::vector<Node> *dataSourcePtr;
	std::vector<std::string> praserResult;

};

