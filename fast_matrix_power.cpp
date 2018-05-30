//
// Created by manout on 18-5-30.
//

#include <vector>
#include <cassert>

using matrix = std::vector<std::vector<int>>;

matrix operator *(const matrix& a, const matrix& b)
{
    assert(a[0].size() == b.size());
    matrix ans(b.size(), std::vector<int>(a[0].size(), 0));
    for (int i = 0;  i < a[0].size(); ++i)
    {
        for (int j = 0; j < b.size(); ++j)
        {
            for (int k = 0; k < b[0].size(); ++k)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

matrix fast_matrix_power(matrix mat, int n)
{
    if (n == 1)
        return mat;
    matrix ans = fast_matrix_power(mat, n / 2);
    ans = ans * ans;
    return n % 2 == 0 ? ans : ans * mat;
}

matrix fast_matrix_power_it(matrix mat, int n)
{
    matrix ans = mat;
    while (n not_eq 0)
    {
        ans = ans * ans;
        if (n % 2 == 1)
        {
            ans = ans * mat;
        }
        n /= 2;
    }
    return ans;
}

