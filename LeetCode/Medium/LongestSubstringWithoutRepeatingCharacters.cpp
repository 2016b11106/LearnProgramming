/**
 * 3. Longest Substring Without Repeating Characters (赞数5439)
 * author 叶晨韬
 * date 2019/5/14
 **/
#include "../Leetcode.h"

/*给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/
int lengthOfLongestSubstring(string s) {
    int res = 0, lo = 0;
    for(int i = 0;i < s.length();i++){
        string str = s.substr(lo, i-lo);
        int idx = str.find(s[i]);
        if(idx == -1){
            res = max(res, i-lo+1);
        }else{
            lo = lo+idx+1;
        }
    }
    return res;
}

int lengthOfLongestSubstring2(string s) {
    int res = 0, lo = 0;
    vector<int> v(256, -1);
    for(int i = 0; i < s.length();i++){
        if(v[s[i]] < lo){
            res = max(res, i-lo+1);
        }else{
            lo = v[s[i]]+1;
        }
        v[s[i]] = i;
    }
    return res;
}