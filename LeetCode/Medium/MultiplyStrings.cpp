/**
 * 43. Multiply Strings (赞数1001)
 * author 叶晨韬
 * date 2019/5/24
 **/
#include "../Leetcode.h"

/*给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积
也表示为字符串形式。
示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"
说明：
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/
string multiply(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int len1 = num1.length(), len2 = num2.length(), len = len1+len2;
    vector<int> v(len+1, 0);
    for(int i = 0;i < len1;i++){
        for(int j = 0;j < len2;j++){
            v[i+j] += (num1[i]-'0') * (num2[j]-'0');
        }
    }
    string s = "";
    int tmp = 0;
    for(int i = 0;i < len+1;i++){
        int x = (v[i]+tmp)%10;
        s += (x+'0');
        tmp = (v[i]+tmp)/10;
    }
    reverse(s.begin(), s.end());
    string res = "";
    for(int i = 0;i < s.length();i++){
        if(res.length() == 0 && s[i] == '0')
            continue;
        res += s[i];
    }
    return res.length() == 0 ? "0" : res;   
}
