//
// Created by manout on 17-12-21.
//

#ifndef ALOGRITHMS_HUGEINT_H
#define ALOGRITHMS_HUGEINT_H

#include <string>
#include <array>

class HugeInt
{
public:
	HugeInt() = default;
	HugeInt(const HugeInt& v) = default;
	HugeInt(HugeInt&&) = default;
	explicit HugeInt(int v);
	explicit HugeInt(const std::string& s);
	HugeInt& operator=(const HugeInt& v) = default;
	int& operator[](int index);
	int operator[](int index) const ;
	
	HugeInt operator+(const HugeInt& b) const;
	HugeInt operator+(int b)const;
	HugeInt&operator+= (const HugeInt& b);
	HugeInt&operator+=(int b);
	HugeInt operator-(const HugeInt& b)const;
	HugeInt operator*(const HugeInt& b)const;
	HugeInt operator*(int b)const;
	HugeInt operator/(const HugeInt& b)const;
	HugeInt operator/(int b)const ;
	HugeInt operator%(const HugeInt& b)const;
	bool operator > (const HugeInt& b)const;
	bool operator >=(const HugeInt& b)const;
	bool operator == (const HugeInt& b)const;
	bool operator == (int b)const;
	bool operator != (const HugeInt& b)const;
	bool operator < (const HugeInt& b)const;
	bool operator <=(const HugeInt& b)const;
	
	friend HugeInt gcd(const HugeInt& a,  const HugeInt& b);
	
	
private:
	using hugeint = int;
	static const int Base = 1000;
	static const int Capacity = 1000;
	int len = 0;
	std::array<int, Capacity> data{0};
};


#endif //ALOGRITHMS_HUGEINT_H
