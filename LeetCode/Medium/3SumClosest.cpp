/**
 * 16. 3Sum Closest (赞数1066)
 * author 叶晨韬
 * date 2019/5/17
 **/
#include "../Leetcode.h"

/*给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    int res, tmp = INT_MAX;
    for(int i = 0;i < sz-2;i++){
        int lo = i+1, hi = sz-1;
        while(lo < hi)
        {
            int k = target-nums[i]-nums[lo]-nums[hi];
            if(abs(k) < tmp){
                res = nums[i]+nums[lo]+nums[hi];
                tmp = abs(k);
            }   
            if(k < 0){
                hi--;
            }else if(k > 0){
                lo++;
            }else{
                return res;
            }
        }
    }
    return res;
}
