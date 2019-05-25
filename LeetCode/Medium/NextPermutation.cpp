/**
 * 31. Next Permutation (赞数1726)
 * author 叶晨韬
 * date 2019/5/20
 **/
#include "../Leetcode.h"

/*实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。
以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
void nextPermutation(vector<int>& nums) {
    int sz = nums.size();
    int i, j;
    for(i = sz-2;i >= 0;i--)
        if(nums[i] < nums[i+1])
            break;
    if(i == -1){
        sort(nums.begin(), nums.end());
        return;
    }
    for(j = sz-1;j >= 0;j--)
        if(nums[j] > nums[i])
            break;
    swap(nums[i], nums[j]);
    reverse(nums.begin()+i+1, nums.end());
}
