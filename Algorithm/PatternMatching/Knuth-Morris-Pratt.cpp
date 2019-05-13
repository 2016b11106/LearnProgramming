/**
 * KMP算法
 * author 叶晨韬
 * date 2019/5/6
 **/
#include <iostream>
#include <string>
const int max_size = 100; //定义next数组的最大长度

//构建next数组
void createNext(int *F, std::string pattern, int len)
{
    F[0] = 0;
    int k = 0;
    for (int i = 1; i < len; i++)
    {
        while (pattern[k] != pattern[i] && k > 0)
            k = F[k - 1];
        if (pattern[k] == pattern[i])
            k++;
        F[i] = k;
    }
}

int KMP(std::string text, std::string pattern)
{
    int len_text = text.length(), len_pattern = pattern.length();
    int F[max_size];
    createNext(F, pattern, len_pattern);
    int k = 0;
    for (int i = 0; i < len_text;)
    {
        int j = F[k], pivot = j; //模式字符串在j位置上开始匹配
        while (i < len_text && j < len_pattern && text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == len_pattern)
            return i - len_pattern;
        if (j == pivot) //第一位不相等
        {
            i += 1; //文本字符串前移一位
            k = 0;
        }
        else
        {
            k = j - 1; //更新next数组的下标
        }
    }
    return -1;
}
