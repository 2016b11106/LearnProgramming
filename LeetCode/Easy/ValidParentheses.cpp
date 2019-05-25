/**
 * 20. Valid Parentheses (赞数2858)
 * author 叶晨韬
 * date 2019/5/17
 **/
#include "../Leetcode.h"

/*给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
示例 1:
输入: "()"
输出: true
示例 2:
输入: "()[]{}"
输出: true
示例 3:
输入: "(]"
输出: false
示例 4:
输入: "([)]"
输出: false
示例 5:
输入: "{[]}"
输出: true
*/
bool isValid(string s) {
    stack<char> sak;
    for(int i = 0;i < s.length();i++){
        if('(' == s[i]){
            sak.push(')');
        }else if('[' == s[i]){
            sak.push(']');
        }else if('{' == s[i]){
            sak.push('}');
        }else{
            if(sak.empty() || sak.top() != s[i])
                return false;
            sak.pop();
        }
    }
    return sak.empty() ? true : false;
}
