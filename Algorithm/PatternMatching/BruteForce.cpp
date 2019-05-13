/**
 * 暴力检索
 * author 叶晨韬
 * date 2019/5/5
 **/
#include <string>

int BF(std::string text, std::string pattern)
{
    int len_text = text.length(), len_pattern = pattern.length();
    for (int i = 0; i <= len_text - len_pattern; i++)
    {
        int j = 0, k = i;
        while (k < len_text && j < len_pattern && text[k] == pattern[j])
        {
            k++;
            j++;
        }
        if (j == len_pattern)
            return i;
    }
    return -1;
}
