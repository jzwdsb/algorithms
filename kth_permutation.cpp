//
// Created by manout on 17-3-16.
//

#include "common_use.h"


/*
 * The set [1, 2, 3 .....] contains a total of n! unique permutations
 * Given n and k, return the kth permutation sequence.
 *
 * 分析：
 *      可以对第一个排序调用之前写的next_permutation实现，但是时间复杂度高
 *      可以使用康托编码来实现，康托编码的原理和展开已在另一个文件中写出，此不在赘述
 *      k2 = k1 % (n - 1)!
 *      a2 = k2 / (n - 2)!
 *      如此重复直到余数为零，每次得到的 a 的值为是这个位置的数在第一个排列中排第几
 */

extern void next_permutation(vector<int> &);

vector<int> get_kth_permutation(int n, int k)
{
    vector<int> ret (n, 0);
    for (int i = 0; i < k; ++i)
    {
        next_permutation(ret);
    }
    return ret;
}
template <typename Sequence>
vector<int> kth_permutation(const Sequence &, int);

vector<int> get_permutation(int n, int k)
{
    vector<int> ret(n, 0);
    //初始化第一个排序
    for(int i = 0; i < n; ++i)
    {
        ret[i] += i;
    }

    kth_permutation(ret, k);
}

int factorial(int n)
{
    int ret = 1;
    for (int i = 1; i <= n; ++i)
    {
        ret *= i;
    }
    return ret;
}

template <typename Sequence>
Sequence kth_permutation(const Sequence& seq, int k)
{
    const int n = Seq.size();
    Sequence S(seq);
    Sequence ret;

    int base = factorial(n -1);
    --k;

    for(int i = n - 1; i > 0; k %= base, base /= i, --i)
    {
        auto a = next(S.begin(), k / base);
        ret.push_back(*a);
        S.erase(a);
    }
    ret.push_back(S[0]);
    return ret;
}
