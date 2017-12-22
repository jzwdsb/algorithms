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

#define chtoint(ch) (ch - '0')
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

HugeInt HugeInt::operator+(const HugeInt &b)
{
	HugeInt ans;
	int i;
	int crray = 0;
	for (i = 0; i < this->len or i < b.len or crray > 0; ++i)
	{
		if (i < this->len) crray += this->data[i];
		if (i < b.len) crray += b.data[i];
		ans[i] = crray % Base;
		crray /= Base;
	}
	ans.len = i;
	return ans;
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
		if(ans[i] < 0)
		{
			carry = ;
			ans[i] += Base;
		}
		else carry = 0;
		while(ans.len > 0 and ans[ans.len - 1] == 0) --ans.len;
		return ans;
	}
}



