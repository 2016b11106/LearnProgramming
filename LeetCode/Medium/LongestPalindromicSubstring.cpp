/**
 * 5. Longest Palindromic Substring (赞数3528)
 * author 叶晨韬
 * date 2019/5/15
 **/
#include "../Leetcode.h"

/*给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：
输入: "cbbd"
输出: "bb"
*/
int LenPalindrome(string s, int lo, int hi){
    while(lo >= 0 && hi < s.length() && s[lo] == s[hi]){
        lo--;
        hi++;
    }
    return hi-lo-1;
}
string longestPalindrome(string s) {
    if(s == "")
        return s;
    int start = 0, len = 0;
    for(int i = 0;i < s.length();i++){
        int len1 = LenPalindrome(s, i , i);
        int len2 = LenPalindrome(s, i , i+1);
        int lenMax = max(len1, len2);
        if(len >= lenMax)
            continue;
        start = i-(lenMax-1)/2;
        len = lenMax;
    }
    return s.substr(start, len);
}
