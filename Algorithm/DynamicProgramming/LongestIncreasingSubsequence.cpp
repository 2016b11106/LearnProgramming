/**
 * 最长上升子序列
 * author 叶晨韬
 * date 2019/5/5
 **/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector<int> &s)
{
    int n = s.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[i] > s[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int res = s[0];
    for (int i = 1; i < n; i++)
        res = max(res, dp[i]);
    return res;
}

int main()
{
    vector<int> s({-2, 2, 4, 1, 6, 10, 2, 3, 4, 5, 6});
    cout << "s: [";
    for (int i = 0; i < s.size() - 1; i++)
        cout << s[i] << ", ";
    cout << s.back() << "]" << endl;
    cout << "The length of LIS: " << LIS(s) << endl;
    return 0;
}
