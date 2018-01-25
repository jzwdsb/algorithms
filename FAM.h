#pragma once
#include "stdafx.h"

/*
 * KMP子字符串查找算法有限自动机实现
 *		认为只需要只开放一个接口和构造函数,不应该支持默认构造
 *		开放此接口作为状态转移函数
 *		const vector<int>& operator[](char c)
 */
class FAM
{
public:
	FAM() = delete;
	FAM(const string& pat) :pattern(pat) { init_FAM(); }
	
	const vector<int>& operator[](char c);

	~FAM();
private:
	void init_FAM();
	// 私有辅助函数，判断一个字符串a是不是字符串b的后缀
	static bool judge_suffix(const string& a, const string& b);
	string pattern;
	map<char, vector<int>> fam;
};

