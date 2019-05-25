/**
 * 15. 3Sum (赞数3706)
 * author 叶晨韬
 * date 2019/5/17
 **/
#include "../Leetcode.h"

/*给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 
a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    for(int i = 0;i < sz && nums[i] <= 0;){
        int target = 0-nums[i];
        int lo = i+1, hi = sz-1;
        while(lo < hi)
        {
            if(nums[lo] + nums[hi] == target){
                vector<int> v{nums[i], nums[lo], nums[hi]};
                res.push_back(v);
                while(lo < hi && nums[lo] == nums[lo+1]) lo++;
                while(lo < hi && nums[hi-1] == nums[hi]) hi--;
                lo++;
                hi--;
            }else if(nums[lo] + nums[hi] < target){
                lo++;
            }else{
                hi--;
            }        
        }
        int k = nums[i];
        while(i+1 < sz && nums[i+1] == k)
            i += 1;
        i += 1;
    }
    return res;
}
