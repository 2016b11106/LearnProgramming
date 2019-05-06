/**
 * 最长公共子序列
 * author 叶晨韬
 * date 2019/5/4
 **/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int LCS(string s1, string s2)
{
    int len1 = s1.length(), len2 = s2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[len1][len2];
}

int main()
{
    string s1 = "aabdef";
    string s2 = "abdef";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "The length of LCS: " << LCS(s1, s2) << endl;
    return 0;
}
