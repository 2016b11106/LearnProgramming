/**
 * 字符串全排列
 * author 叶晨韬
 * date 2019/4/29
 **/
#include <iostream>
#include <algorithm>
#include <string>

// ABC-->[ABC,ACB,BAC,BCA,CBA,CAB]
void _stringPermutation(std::string s, int idx, unsigned int len)
{
    if (idx == len - 1)
    {
        std::cout << s << std::endl;
        return;
    }
    for (int i = idx; i < len; i++)
    {
        std::swap(s[idx], s[i]);
        _stringPermutation(s, idx + 1, len);
        std::swap(s[i], s[idx]);
    }
}

void stringPermutation(std::string s)
{
    _stringPermutation(s, 0, s.length());
}
