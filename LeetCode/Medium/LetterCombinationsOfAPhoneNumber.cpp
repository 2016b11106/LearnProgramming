/**
 * 17. Letter Combinations of a Phone Number (赞数2117)
 * author 叶晨韬
 * date 2019/5/17
 **/
#include "../Leetcode.h"

/*给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
1XXX  2abc 3def
4ghi  5jkl 6mno
7pqrs 6tuv 9wxyz
示例:
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。*/
void letterCombinationsResult(vector<string> &res, string &s, string digit[],
                                 int idx, string digits){
    if(idx == digits.length()){
        res.push_back(string(s.begin(), s.end()));
        return;
    }
    int i = digits[idx]-'0';
    for(int j = 0;j < digit[i].length();j++){
        s += digit[i][j];
        letterCombinationsResult(res, s, digit, idx+1, digits);
        s = s.substr(0, s.length()-1);
    }
}
vector<string> letterCombinations(string digits) {
    string digit[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    if(digits.length() == 0)
        return res;
    string s = "";
    letterCombinationsResult(res, s, digit, 0, digits);
    return res;
}
