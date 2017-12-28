//
// Created by manout on 17-12-24.
//
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

/** 平时调试时将 强制内联 设置为空*/
#define __always_inline
/** 字符转换宏　*/
#define todigit(ch)     ((ch) - '0')
#define tochar(ch)      ((ch) + '0')
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


/** 计算长整数的乘方*/
long long myPow(int num, int n)
{
	if (n == 1)
	{
		return num;
	}
	if (n % 2 == 1)
	{
		long long ans = myPow(num, (n - 1) / 2);
		return ans * ans  * num;
	}
	else
	{
		long long ans = myPow(num, n / 2);
		return ans * ans;
	}
}


std::string operator+(std::string num, int a)
{
	std::reverse(num.begin(), num.end());
	std::string::iterator it = num.begin();
	int carry = 0;
	while (a not_eq 0 and it not_eq num.end())
	{
		if (todigit(*it) + a % 10 + carry > 10)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		*it = static_cast<char>(tochar((todigit(*it) + a % 10 + carry) % 10));
		++it;
		a /= 10;
	}
	if (carry not_eq 0 or a not_eq 0)
	{
		if (carry not_eq 0)
		{
			num.push_back(static_cast<char> (tochar(carry + a % 10)));
			a /= 10;
		}
		while(a not_eq 0)
		{
			num.push_back(static_cast<char>(tochar(a % 10)));
			a /= 10;
		}
	}
	
	std::reverse(num.begin(), num.end());
	return num;
}

std::string long_num_plus(const std::string& a, const std::string& b)
{
	int carry = 0;
	std::string ans;
	/** a is long number iterator */
	/** b is short number iterator*/
	std::string::const_reverse_iterator a_it, a_end;
	std::string::const_reverse_iterator b_it, b_end;
	if (a.length() >= b.length())
	{
		a_it = a.rbegin();
		a_end = a.rend();
		b_it = b.rbegin();
		b_end = b.rend();
	}
	else
	{
		a_it = b.rbegin();
		a_end = b.rend();
		b_it = a.rbegin();
		b_end = a.rend();
	}
	while (b_it not_eq b_end and a_it not_eq a_end )
	{
		char curr_bit = static_cast<char>(todigit(*a_it) + todigit(*b_it) + carry);
		if (curr_bit >= 10)
		{
			carry = 1;
			curr_bit %= 10;
		}
		else
		{
			carry = 0;
		}
		ans.push_back(tochar(curr_bit));
		++a_it;
		++b_it;
	}
	
	if(a_it not_eq a_end or carry not_eq 0 )
	{
		if (carry not_eq 0)
		{
			char curr_bit = 0;
			if (a_it not_eq a.rend())
			{
				curr_bit = static_cast<char>((todigit(*a_it) + carry));
				if (curr_bit >= 10)
				{
					curr_bit = 1;
					ans.push_back(todigit(curr_bit % 10));
					ans.push_back(static_cast<char>(tochar(curr_bit / 10 + 1)));
				}
			} else
			{
				ans.push_back('1');
			}
		}
		while (a_it not_eq a_end)
		{
			ans.push_back(*a_it);
			++a_it;
		}
	}
	std::reverse(ans.begin(), ans.end());
	return ans;
}

std::string long_num_mult(const std::string& num, int n)
{
	// TODO here is going to implment long num mult
}

std::string long_num_mult(const std::string& a, const std::string& b)
{

}

std::string highPrecisionCompution(std::string& num, int n)
{
	eraseBackZero(num);
	int digit = doubleToInt(num);
	int countDec = countAfterDot(num);
	
	std::string ans = std::to_string(myPow(digit, n));
	std::string::reverse_iterator rit = ans.rbegin();
	std::string::size_type pos = ans.length() - countDec * n ;
	ans.insert(pos, 1, '.');
	return ans;
}

#undef tochar
#undef todigit
