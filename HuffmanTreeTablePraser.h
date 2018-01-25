#pragma once

#include "all_include.h"
#include "HuffmanTreeTable.h"
#include <memory>
// 编译顺序未知所以即使包含HuffmanTreeTable头文件仍有可能在其之前编译，所以要加上对HuffmanTreeTabl类的超前声明
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

