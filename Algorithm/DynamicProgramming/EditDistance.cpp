/**
 * 最小编辑距离问题
 * author 叶晨韬
 * date 2019/5/5
 **/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int editDistance(string s1, string s2)
{
    int len1 = s1.length(), len2 = s2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; i++)
        dp[i][0] = i;
    for (int i = 1; i <= len2; i++)
        dp[0][i] = i;
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            dp[i][j] = min(dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1), min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            //dp[i-1][j]+1表示删掉字符串s1最后一个字符s1[i]
            //dp[i][j-1]+1表示给字符串添加s2最后一个字符
            //dp[i-1][j-1]+?表示改变,相同则不需操作次数+0,不同则需要+1
        }
    }
    return dp[len1][len2];
}

int main()
{
    string s1 = "cafe", s2 = "coffee";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "The step of edit s1->s2: " << editDistance(s1, s2) << endl;
    return 0;
}
