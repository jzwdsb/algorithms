//
// Created by manout on 17-12-24.
//
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
/** 高精度浮点数乘方的实现
 *  应先将其转换为长整数然后再乘方， 最后将小数点移动到合适位置*/


/** 先擦除输入字符串小数点后面多余的 0 */
__always_inline
std::string& eraseBackZero(std::string& str)
{
	if (str.find('.') not_eq std::string::npos)
	{
		str.erase(str.find_last_not_of('0') + 1);
	}
	return str;
}


/** 再将输入字符串转化为长整数*/
__always_inline
int doubleToInt( std::string num)
{
	num.erase(num.find('.'), 1);
	std::cout << num << std::endl;
	int ans = std::stoi(num);
	return ans;
}


/** 计算小数点后面有多少位*/
__always_inline
int countAfterDot(const std::string& str)
{
	std::string::size_type dotPos = str.find('.') + 1u;
	return static_cast<int>(str.length() - dotPos);
}


std::string highPrecisionCompution(const std::string& num, int n)
{
	int digit = doubleToInt(num);
	int countDec = countAfterDot(num);
	
}
