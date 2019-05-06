/**
 * 最长公共子串
 * author 叶晨韬
 * date 2019/5/5
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
    int res = 0;
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return res;
}

int main()
{
    string s1 = "abcdfwetd";
    string s2 = "abdwetd";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "The length of LCS: " << LCS(s1, s2) << endl;
    return 0;
}
