/**
 * 9. Palindrome Number (赞数1389)
 * author 叶晨韬
 * date 2019/5/15
 **/
#include "../Leetcode.h"

/*判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:
输入: 121
输出: true
示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
*/
bool isPalindrome(int x) {
    if(x < 0)
        return false;
    long long n = 0, k = x;
    while(x != 0)
    {
        n = n*10+x%10;
        x = x/10;
    }
    return n == k;
}
