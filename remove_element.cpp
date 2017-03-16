//
// Created by manout on 17-3-11.
//

#include "common_use.h"

/*
 *      Given an array and a value, remove all instances of that value in
 * place and return the new length. The order of elements can be changed.
 * it doesn't matter what you leave beyond the new length.
 */


int remove_element()(vector<int> &nums, int target){
    int index = 0;
    for (int i = 0 ;i < nums.size(); ++i) {
        if(nums[] != target ){
            nums[index++] = nums[i];
        }
    }
    return index;
}

int remove_element_(vector<int> &nums, int target){
    return distance(nums.begin(), remove(nums.begin(),nums.end(), target));
}