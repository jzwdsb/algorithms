//
// Created by manout on 18-1-14.
//
#include <stack>
#include <string>
#include <sstream>

using std::stringstream;
using std::stack;
using std::string;
using std::stoi;
__always_inline
static bool isoperator(const string& s)
{
	if (s.size() > 1u)
		return false;
	switch (s[0])
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			return true;
		default:
			return false;
	}
}

#define OP(op)  first op second
/** The input guarantee that two consecutive symbol are separated by space */
int postfix_string(const string& e)
{
	stringstream ss(e);
	string token;
	stack<int> s;
	int first, second;
	while (ss >> token)
	{
		if (not isoperator(token))
		{
			s.push(stoi(token));
		}
		else
		{
			second = s.top();
			s.pop();
			first = s.top();
			s.pop();
			switch (token[0])
			{
				case '+':
					s.push(OP(+));
					break;
				case '-':
					s.push(OP(-));
					break;
				case '*':
					s.push(OP(*));
					break;
				case '/':
					s.push(OP(/));
					break;
				case '%':
					s.push(OP(%));
					break;
				default:
					break;
			}
		}
	}
	if (s.size() == 1)
	{
		return s.top();
	}
	throw std::invalid_argument("the expression is not legal");
}
