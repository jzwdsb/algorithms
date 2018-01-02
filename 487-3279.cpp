//
// Created by manout on 17-12-29.
//
#include <iostream>
#include <string>


int ch_to_num(char ch)
{
	switch (toupper(ch))
	{
		case 'A':
		case 'B':
		case 'C':
			return '2';
		case 'D':
		case 'E':
		case 'F':
			return '3';
		case 'G':
		case 'H':
		case 'I':
			return '4';
		case 'J':
		case 'K':
		case 'L':
			return '5';
		case 'M':
		case 'N':
		case 'O':
			return '6';
		case 'P':
		case 'R':
		case 'S':
			return '7';
		case 'T':
		case 'U':
		case 'V':
			return '8';
		case 'W':
		case 'X':
		case 'Y':
			return '9';
		case '-':
			return ' ';
		default:
			return ' ';
	}
}
