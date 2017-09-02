//
// Created by manout on 17-9-2.
//
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <exception>
#include <uv.h>

using std::stringstream;
using std::string;
using ID_container = std::vector<string>;
using std::unordered_map;

// ID码的每一位的权重
int weight [] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

// 取模后的 Z 值与 校验码的映射关系
unordered_map<int, char> check_map =
        {
                {0, '1'},
                {1, '0'},
                {2, 'X'},
                {3, '9'},
                {4, '8'},
                {5, '7'},
                {6, '6'},
                {7, '5'},
                {8, '4'},
                {9, '3'},
                {10, '2'}
        };


ID_container examine_ID(const ID_container& id_set)
{
	ID_container ret;
	int check_sum = 0;
	char checkcode ;
	for (const auto &st : id_set)
	{
		check_sum = 0;
		for (size_t i = 0; i < st.size() - 1; ++i)
		{
			switch(st[i])
			{
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					check_sum += (st[i] - '0') * weight[i];
					break;
				case 'X':
					check_sum += 10 * weight[i];
					break;
				default:
					throw std::out_of_range("invalid argument");
			}
			checkcode = check_map[check_sum % 11];
			if (checkcode not_eq *st.rbegin())
			{
				ret.push_back(st);
			}
		}
	}
	if (ret.empty())
	{
		ret.emplace_back("All passed");
	}
	return ret;
}

