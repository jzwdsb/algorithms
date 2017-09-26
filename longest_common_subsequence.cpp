//
// Created by manout on 17-9-25.
//

#include "common_use.h"

using Matrix = vector<vector<int>>;


int longest_common_subsequence(string a, string b)
{
	Matrix mat(a.size() + 1, Matrix::value_type(b.size() + 1, 0));
	
	for (int i = 1; i <= a.size(); ++i)
	{
		for (int j = 1; j <= b.size(); ++i)
		{
			if(a[i - 1] == b[j - 1])
			{
				mat[i][j] = mat[i + 1][j + 1] + 1;
			}
			else
			{
				mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
			}
		}
	}
	return mat[a.size()][b.size()];
}
