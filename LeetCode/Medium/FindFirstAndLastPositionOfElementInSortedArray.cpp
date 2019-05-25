/**
 * 34. Find First and Last Position of Element in Sorted Array (赞数1535)
 * author 叶晨韬
 * date 2019/5/22
 **/
#include "../Leetcode.h"

/*给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置
和结束位置。你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。
示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/
vector<int> searchRange(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size()-1;
    while(lo <= hi)
    {
        int mid = (lo+hi)/2;
        if(nums[mid] == target){
            int i = mid-1, j = mid+1;
            while(i >= 0 && nums[i] == target)
                i--;
            while(j <= nums.size()-1 && nums[j] == target)
                j++;
            return vector<int>{i+1, j-1};
        }else if(nums[mid] < target){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    return vector<int>{-1, -1};
}
