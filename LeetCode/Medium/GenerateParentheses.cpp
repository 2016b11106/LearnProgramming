/**
 * 22. Generate Parentheses
 * author 叶晨韬
 * date 2019/5/18
 **/
#include "../Leetcode.h"

/*给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
例如，给出 n = 3，生成结果为：
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
void generateParenthesisResult(vector<string> &res, string s, int ln, 
                                int rn, int n) {
    if(ln == n && rn == n){
        res.push_back(s);
        return;
    }
    if(ln < n){
        generateParenthesisResult(res, s+'(', ln+1, rn, n);
    }
    if(rn < ln){
        generateParenthesisResult(res, s+')', ln, rn+1, n);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateParenthesisResult(res, "", 0, 0, n);
    return res;
}
