/**
 * 33. Search in Rotated Sorted Array (赞数2362)
 * author 叶晨韬
 * date 2019/5/22
 **/
#include "../Leetcode.h"

/*假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
示例 1:
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size()-1;
    while(lo <= hi)
    {
        int mid = (lo+hi)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] >= nums[lo]){
            if(nums[lo] <= target && target < nums[mid])
                hi = mid-1;
            else
                lo = mid+1;
        }else if(nums[mid] <= nums[hi]){
            if(nums[mid] < target && target <= nums[hi])
                lo = mid+1;
            else
                hi = mid-1;
        }
    }
    return -1;
}
