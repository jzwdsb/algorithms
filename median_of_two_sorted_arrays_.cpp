/*
 * 
 * There are two sorted arrays A and B of size and n respectivelt.
 * Find the median of the two sorted arrays. The overall run time
 * should be O(log(m + n))
 * 
 * 有两个长度不同已排序的数组 A 和 B，找到这两者的所有元素的中间值。
 * 时间复杂度的上限应该是 O(log(m + n))
 * 
 * 这个问题可以化为更一般的形式，存在两个有序数组，从这两个数组的全部元素中找出第k大的元素
 * 
 *
 *
 * 可以利用二分法的思想，假设A, B两数组的长度都大于 k / 2，将A的第 k / 2 个元素与B的第 k / 2 个元素进行比较
 * 如果相等，则说明这是第 k 大的元素，直接返回其中一个即可，如果A小于B，说明A的前一半元素都小于第 k 大的元素
 * 可以直接删掉，反之对B也成立
 * 
 * 
 */
 
#include <vector>
using std::vector;

int fint_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B,int n, int k);

double  search_median_(const vector<int> &a,const  vector<int> &b){
	const int m = a.size();
	const int n = b.size();
	int total = m + n;
	if(total & 0x1){
		return find_kth(a.begin(), m, b.begin(), n, total / 2);
	}
	else {
		return find_kth(a.begin(), m, b.begin(), n, total / 2);
	}
}

int find_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k){
	//always assume that m is equal or small than n
	//假设m是不大于n的
	if (m == 0){
		return *(B + k - 1);
	}
	if (k == 1){
		return min(*A, *B):
	}

	//divide k into two parts
	//将k划分为两半
	
	int ia = min(k / 2, m)		//如果a的长度小于 k / 2，则直接取至末尾	
	int ib = k - ia;		//k - ia  保证ia, ib前一共有k - 1个数
	if(*(A + ia - 1) < *(B + ib - 1)){
		return find_kth(A + ia, m - ia, B , n, k - ia);
	}
	else if(*(A + ia - 1) > *(B + ib - 1)){
		return find_kth(A, m, B + ib, n - ib, k - ib);
	}
	else{
		return A[ia - 1];
	}
}
