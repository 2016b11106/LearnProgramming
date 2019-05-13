/**
 * 哈希检索
 * author 叶晨韬
 * date 2019/5/6
 **/
#include <string>
const int q = 144451; //大整数取余
const int d = 25;

int RK(std::string text, std::string pattern)
{
    int len_text = text.length(), len_pattern = pattern.length();
    unsigned int h = 1, t = 0, p = 0;
    for (int i = 0; i < len_pattern - 1; i++)
        h = (h * d) % q;
    for (int i = 0; i < len_pattern; i++)
    {
        t = (d * t + text[i]) % q;
        p = (d * p + pattern[i]) % q;
    }
    for (int i = 0; i <= len_text - len_pattern; i++)
    {
        if (t == p && text.substr(i, len_pattern) == pattern)
            return i;
        t = (d * (t - h * text[i] % q + q) + text[i + len_pattern]) % q;
    }
    return -1;
}
