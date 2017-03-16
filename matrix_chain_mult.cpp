#include "stdafx.h"

class matrix
{
public:
	matrix() :row(0), col(0), mat(nullptr) {}
	matrix(size_t r, size_t c) :row(r), col(c), mat(new size_t[row*col])
	{
		memset(mat, 0, row * col * sizeof(int));
	}
	matrix(size_t r) :row(r), col(r), mat(new size_t[row * col])
	{
		memset(mat, 0, row * col * sizeof(int));
	}
	~matrix() { delete[] mat; }
	size_t* operator[](size_t r) { return mat + r * col; }
private:
	size_t row, col;
	size_t *mat;
};


pair<matrix, matrix> matrix_chain(vector<size_t> chain)
{
	size_t len = chain.size() - 1;
	matrix m(len, len), s(len, len);
	for (size_t i = 0; i < len; ++i)
	{
		m[i][i] = 1;
	}
	for(size_t l = 2; l <= len; ++l)
	{
		for (size_t i = 1; i <= len - l + 1; ++i)
		{
			size_t j = i + l - 1;
			m[i][j] = SIZE_MAX;
			for (size_t k = i; k < j - 1; ++k)
			{
				size_t q = m[i][k] + m[k + 1][j] + chain[i - 1] * chain[k] * chain[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	return make_pair(m, s);
}
