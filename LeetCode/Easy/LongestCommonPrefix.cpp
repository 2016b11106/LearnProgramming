/**
 * 14. Longest Common Prefix (赞数1333)
 * author 叶晨韬
 * date 2019/5/15
 **/
#include "../Leetcode.h"

/*编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
示例 1:
输入: ["flower","flow","flight"]
输出: "fl"
示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
*/
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0)
        return "";
    int k = strs[0].length();
    for(int i = 1; i < strs.size();i++){
        string s = strs[i];
        int j = 0;
        for(;j < k && j < s.length();j++){
            if(strs[0][j] != strs[i][j]){
                k = j;
                break;
            }
        }
        if(j == s.length())
            k = s.length();
    }
    return strs[0].substr(0, k);
}
