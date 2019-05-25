/**
 * 11. Container With Most Water (赞数3167)
 * author 叶晨韬
 * date 2019/5/15
 **/
#include "../Leetcode.h"

/*给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出
其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
示例:
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/
int maxArea(vector<int>& height) {
    int lo = 0, hi = height.size()-1;
    int res = -1, hgt;
    while(lo < hi)
    {
        if(height[lo] > height[hi]){
            hgt = height[hi];
            hi--;
        }else{
            hgt = height[lo];
            lo++;
        }
        int area = hgt * (hi-lo+1);
        res = max(res, area);
    }            
    return res;
}
