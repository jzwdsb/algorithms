//
// Created by manout on 17-12-22.
//
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;


const char* hex_char_to_bin(char c)
{
	switch(toupper(c))
	{
		case '0': return "0000";
		case '1': return "0001";
		case '2': return "0010";
		case '3': return "0011";
		case '4': return "0100";
		case '5': return "0101";
		case '6': return "0110";
		case '7': return "0111";
		case '8': return "1000";
		case '9': return "1001";
		case 'A': return "1010";
		case 'B': return "1011";
		case 'C': return "1100";
		case 'D': return "1101";
		case 'E': return "1110";
		case 'F': return "1111";
		default: return "null";
	}
}

string hexTobin(const string& str)
{
	string bin;
	for (string::const_iterator it = str.begin(); it not_eq str.end(); ++it)
	{
		bin.append(hex_char_to_bin(*it));
	}
	return bin;
}
