/*
 *     Given an unsorted array of integers, find the length of the longest 
 * consecutive elements sequence.
 *     For example, Given [100, 4, 200, 1, 3, 2], the longest consecutive 
 * sequence is [1, 2, 3, 4].return its length: 4.
 *     your alorithm should run in O(n) complexity.
 *     给出一个未排序的整型数组，找出其中最长的连续的元素的序列的长度。
 *     示例，给出[100, 4, 200, 1, 3, 2]，最长的连续子序列为[1, 2, 3, 4]。
 * 返回长度4。
 *     你的算法的时间复杂度应为O(n)
 *     如果允许O(nlogn)的时间复杂度，那么可以先排序，但是本题要求O(n).
 *     用一个哈希表unordered_map<int, bool> used记录每个元素是否被使用，对每个元素
 *     以该元素为中心，向左右扩张，直到不连续位置，记录下最长的长度
 */

#include <vector>
using std::vector;

#define not !
#define not_eq !=


//Longest consecutive sequence
//时间复杂度O(n), 空间复杂度O(n)
int  longestConsecutive(const vector<int> &nums){
	unordered_map<int, bool> used;

	//标记每个数字
	for(auto i : nums){
		used[i] = false;
	}
	int longest = 0;
	for(auto i : nums){
		//如果已经对该元素扩展过，那么直接略过
		if(used[i]) continue;
		int length = 1;
		used[i] = true;
		for(int j = i + 1; used.find(j) != used.end(); ++j){
			//对每个扩展过程中访问过的元素进行标记
			used[j] = true;
			++length;
		}

		for (int j = i - 1; used.find(j) != used.end(); --j){
			used[j] = true;
			++length;
		}
		
		//迭代到最后留下的是最大值
		longest = max(longest, length);
	}
	return longest;
}



//可以改用含有union, find的操作，连续序列可以用两端和长度来表示，本来用两端就已表示，将两端分别暴露出来
//用 unordered_map<int, int> map 来存储

int merger_cluster(unordered_map<int, int> &, int, int);


int longest_consecutive_(vector<int> &nums){
	unordered_map<int, int> map;
	int size = nums.size();
	if (not size) return 0;
	for(int i = 0; i < size; ++i){
		//如果为尾后则表示当前数并未被记录其作为区间中心的连续区间长度
		if(map.find(nums[i] not_eq map.end())continue;
		map[nums[i]] = 1;
		if(map.find(nums[i] - 1) not_eq map.end()){
			l = max(l, max(map, nums[i] - 1, nums[i]));
		}
		if(map.find(nums[i] + 1) not_eq map.end()){
			l = max(l, merger_cluster(map , nums[i], nums[i] + 1));
		}
	}
	return l;
}

//类似于递推式，记录下每个数字作为端点时的最大长度
int merger_cluster(unordered_map<int, int> &map, int left, int right){
	//
	int upper = right + map[right] - 1;
	int lower = left - map[left] + 1;
	int length = upper -  lower + 1;
	map[upper] = length;
	map[lower] = lower;
	return length;
}

