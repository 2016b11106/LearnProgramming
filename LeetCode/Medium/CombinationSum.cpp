/**
 * 39. Combination Sum (赞数1946)
 * author 叶晨韬
 * date 2019/5/24
 **/
#include "../Leetcode.h"

/*给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以
使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。
说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
void combinationSumResult(vector<vector<int>> &res, vector<int> &candidates, 
                            vector<int> &v, int target, int sum, int idx){
    for(int i = idx;i < candidates.size();i++){
        sum += candidates[i];
        if(sum == target){
            v.push_back(candidates[i]);
            res.push_back(v);
            v.pop_back();
            return;
        }else if(sum < target){
            v.push_back(candidates[i]);
            combinationSumResult(res, candidates, v, target, sum, i);
            v.pop_back();
        }else{
            return;
        }
        sum -= candidates[i];
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> v;
    vector<vector<int>> res;
    combinationSumResult(res, candidates, v, target, 0, 0);
    return res;
}
