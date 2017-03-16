/*
 * 	Given an array of integers, find two numbers such that they add up to target number.
 *	The function twoSum should return indices of the two numbers that they add up to the target, 
 * where index 1 must less than index 2. Please note your returned answers(both index 1 and index 2) 
 * are not zero-based.
 * 	给出一个整型数组， 找到两个加起来等于目标值的数字
 * 	函数twoSum应该返回两个数字的下标。第一个数字的下标应该小于第二个数字的下标。
 * 注意你的返回值不应该是为零
 * 
 * 方法1：暴力，复杂度O(n2)，会超时
 * 方法2：hash，维护一个哈希表，存储每个数的下标，复杂度O(n)
 * 方法3：先排序，然后左右夹逼，排序O(nlogn)，左右夹逼O(n)，最终O（nlon)。
 * 	  但是注意，这题需要返回的是下标，而不是数字本身，因此这个方法行不通。
 *
 * */

#include <vector>
#include <map>

#define not_eq	 !=
#define and	 &&
using std::unordered_map;
using std::vector;


vector<int> two_sum(vector<int> nums, int target){

	unordered_map<int, int> mapping;
	vector<int> result;
	//标记每个数字的下标
	for(int i = 0; i < nums.size(); ++i){
		mapping[nums[i]] = i;
	}

	for (int i = 0; i < nums.size(); ++i){
		//target - nums[i] = gap，找到另一个加数且其下标大于前一个加数
		const int gap = target - nums[i];
		if(mapping.find(gap) not_eq mapping.end() and mapping[gap] > i){
			//向结果中添加其下标，在本题中，下标从1开始
			result.push_back(i + 1);
			result.push_back(mapping[gap] + 1)
		}
	}
	
	return result;
}
