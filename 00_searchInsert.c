/*
35. 搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0

*/
#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target){
        int left = 0;
        int right = numsSize - 1;
        int mid;
        if(target < nums[0]){
                return 0;
        }
        if(target > nums[numsSize-1]){
                return numsSize;
        }

        while(left < right){
                mid = (left + right) / 2;
                if(target > nums[mid]){ // target 位于右侧
                        left = mid + 1;
                }else{
                        right = mid;
                }
        }
        return left;
}

int main (int argc, char **argv){
	int nums[] = {1, 3, 5, 7};
	int target = 6;
	int length = sizeof(nums)/sizeof(nums[0]);	
	printf("%d\n",searchInsert(nums, length, target));
}
