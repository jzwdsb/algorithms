//
// Created by manout on 17-12-21.
//

#include "HugeInt.h"

HugeInt::HugeInt(int v):len(0)
{
	while (v > 0)
	{
		++len;
		data[len] = (v % Base);
		v /= Base;
	}
}

#define chtoint(ch) ((ch) - '0')
HugeInt::HugeInt(const std::string& s)
{
	int j;
	this->len = 0;
	j = 1;
	for (int i = s.length() - 1; i >= 0; --i)
	{
		data[len] += chtoint(s[i]) * j;
		j *= 10;
		if (j >= Base)
		{
			j = 1;
			data[++len] = 0;
		}
	}
	if (data[len] > 0)
	{
		++len;
	}
}

#undef chtoint

int &HugeInt::operator[](int index)
{
	return this->data[index];
}

int HugeInt::operator[](int index) const
{
	return this->data[index];
}

HugeInt HugeInt::operator+(const HugeInt &b)const
{
	HugeInt ans(*this);
	ans += b;
	return ans;
}

HugeInt HugeInt::operator+(int b) const
{
	HugeInt ans(*this);
	ans += b;
	return ans;
	
}

HugeInt &HugeInt::operator+=(int b)
{
	int i = 0;
	int p = 1;
	do
	{
		this->data[i] += b % Base;
		p *= Base;
		b /= Base;
		++i;
	}while (i < this->len and b > 0);
	return *this;
}

HugeInt &HugeInt::operator+=(const HugeInt &b)
{
	int i;
	int carry = 0;
	for (i = 0; i < this->len or i < b.len or carry > 0; ++i)
	{
		if (i < this->len) carry += this->data[i];
		if (i < b.len) carry += b.data[i];
		this->data[i] = carry % Base;
		carry /= Base;
	}
	this->len = i;
	return *this;
}

HugeInt HugeInt::operator-(const HugeInt &b) const
{
	HugeInt ans;
	int carry = 0;
	ans.len = this->len;
	for (int i = 0; i < ans.len; ++i)
	{
		ans[i] = this->data[i] - carry;
		if (i < b.len)ans[i] -= b[i];
		if (ans[i] < 0)
		{
			carry = 1;
			ans[i] += Base;
		}
		else carry = 0;
	}
		while(ans.len > 0 and ans[ans.len - 1] == 0) --ans.len;
		return ans;
	
}

HugeInt HugeInt::operator*(const HugeInt &b) const
{
	HugeInt ans;
	if (b.len == 0) return ans;
	int p = 1;
	/** 两个大数相乘的逻辑
	 *  第一个从第二个数的最低位开始，依次相乘
	 *  最后相加得到
	 *  基数为Base
	 *  每过一位乘以Base*/
    for (int i = 0; i < this->len; ++i)
	{
		ans += b * (this->data[i] * p);
		p *= Base;
	}
}

HugeInt HugeInt::operator*(int b) const
{
	HugeInt ans;
	hugeint carry = 0;
	hugeint i = 0;
	if (b == 0) return ans;
	/** 乘的逻辑是从最低位开始乘，每位乘以当前乘数
	 *  然后模 base 的结果赋予当前位
	 *  然后 除以 base 作为下一位的进位*/
	for	(; i < this->len or carry > 0; ++i)
	{
		if (i < this->len) carry += this->data[i] * b;
		ans[i] = carry % Base;
		carry /= Base;
	}
	ans.len = i;
	return ans;
}

HugeInt HugeInt::operator/(const HugeInt &b) const
{
	HugeInt ans, carry;
	int left, right, mid;
	for (int i = this->len - 1; i >= 0; --i)
	{
		carry = carry * Base + *this;
		left = 0;
		right = Base - 1;
		while (left < right)
		{
			mid = (left + right + 1) / 2;
			if (b * mid <= carry) left =mid;
			else right = mid - 1;
		}
		ans[i] = left;
		carry = carry - b * left;
	}
	ans.len = this->len;
	while (ans.len > 0 and ans[ans.len - 1] == 0) -- ans.len;
	return ans;
}

HugeInt HugeInt::operator/(int b)const
{
	HugeInt ans;
	int c = 0;
	for (int i = this->len - 1; i >= 0; --i)
	{
		c = c * Base + this->data[i];
		ans[i] = c / b;
		c %= b;
	}
	ans.len = this->len;
	while (ans.len > 0 and ans[ans.len - 1] == 0) --ans.len;
	return ans;
}

HugeInt HugeInt::operator%(const HugeInt &b) const
{
	HugeInt ans, carry;
	int left, mid, right;
	for (int i = this->len - 1; i >= 0; --i)
	{
		carry = carry * Base + this->data[i];
		left = 0;
		right = Base - 1;
		while (left < right)
		{
			mid = (left + right + 1) / 2;
			if (b * mid <= carry) left = mid;
			else right = mid - 1;
		}
		ans[i] = left;
		carry = carry - b *left;
	}
	return carry;
}

bool HugeInt::operator>(const HugeInt &b) const
{
	int i;
	if (this->len not_eq b.len) return this->len > b.len;
	i = this->len - 1;
	while (i >= 0 and this->data[i] == b[i])--i;
	if (i < 0)return false;
	return this->data[i] > b[i];
}

bool HugeInt::operator>=(const HugeInt &b) const
{
	return *this > b or *this == b;
}

bool HugeInt::operator==(const HugeInt &b) const
{
	int i = 0;
	if (this->len not_eq b.len)return false;
	
	while (this->data[i] == b[i])++i;
	return this->len == i;
}
bool HugeInt::operator==(int b) const
{
	int sum = 0;
	int p = 1;
	for (int i = 0; i < this->len; ++i)
	{
		sum += this->data[i] * p;
		p *= Base;
	}
	return p == b;
}
bool HugeInt::operator!=(const HugeInt &b) const
{
	return not (*this == b);
}

bool HugeInt::operator<(const HugeInt &b) const
{
	return *this not_eq b and not (*this > b);
}

bool HugeInt::operator<=(const HugeInt &b) const
{
	return *this < b or *this == b;
}

HugeInt gcd(const HugeInt &a, const HugeInt &b)
{
	if (b == 0)return a;
	return gcd (b, a % b);
}












