/**
 * 14. Longest Common Prefix (赞数1333)
 * author 叶晨韬
 * date 2019/5/15
 **/
#include "../Leetcode.h"

/*编写一个函数来查找字符串数组中最长的公共前缀字符串。
如果没有公共前缀，返回一个空字符串""
Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
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
