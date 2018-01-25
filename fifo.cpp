//
// Created by manout on 17-12-27.
//

#include <vector>
#include <algorithm>

extern std::vector<int> read_sequence;

/** 最大物理块数*/
const int BLOCK_MAX_SIZE = 10u;

/** 页表块数*/
const int TLB_SIZE = 4u;

/** 缺页计数*/
int pageFalutCount = 0;

/** 页面置换计数*/
int pageReplaceCount = 0;

/** 快表*/
std::vector<int> fastPageTable;

/** 页表*/
std::vector<int> pageTable;

int blockCount = BLOCK_MAX_SIZE;

void fifo()
{
	
	for (std::vector<int>::const_iterator it = read_sequence.begin();
		 it not_eq read_sequence.end();++it)
	{
		std::vector<int>::iterator fastPos = std::find(fastPageTable.begin(), fastPageTable.end(), *it);
		if (fastPos == fastPageTable.end())
		{
			/** 这里处理快表不命中*/
			std::vector<int>::iterator pagePos = std::find(pageTable.begin(), pageTable.end(), *it);
			if (pagePos == pageTable.end())
			{
				/** 这里是页表不命中 */
				
				if (blockCount > 0)
				{
					/** 物理块计数*/
					--blockCount;
					pageTable.push_back(*it);
				}
				/** 这里处理置换算法*/
				else
				{
					/** 使用 fifo 算法置换最先进入队列的页*/
					/** 由于发生置换再挂起1000毫秒*/
					// sleep(1000);
					pageTable.erase(pageTable.begin());
					pageTable.push_back(*it);
					++pageReplaceCount;
				}
				/** 挂起1000毫秒　*/
				// sleep(1000);
				++pageFalutCount;
			} else
			{
				/** 这里处理命中后将页面换到队尾*/
				pageTable.erase(pagePos);
				pageTable.push_back(*it);
			}
			/** 这里快表的置换也是用 fifo*/
			if (fastPageTable.size() < TLB_SIZE)
			{
				fastPageTable.push_back(*it);
			}
			else
			{
				fastPageTable.erase(fastPageTable.begin());
				fastPageTable.push_back(*it);
			}
		}
		else
		{
				fastPageTable.erase(fastPos);
				fastPageTable.push_back(*it);
		}
	}
}
