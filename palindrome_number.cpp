#include "common_use.h"

/*
 *		Determine whether an integer is a palindrome. Do this without extra space.
 */

//不断的比较未访问的最后一位和第一位
bool is_palindrome(int x)
{
	if (x < 0) return false;
	int d = 1;
	//记位数
	while (x / d >= 10)d *= 10;
	while (x > 0)
	{
		int front = x / d;
		int back = x % 10;
		if (front not_eq back)return false;
		x = x % d / 10;
		d /= 100;
	}
	return true;
}
