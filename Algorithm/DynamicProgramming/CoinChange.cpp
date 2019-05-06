/**
 * 硬币找零
 * author 叶晨韬
 * date 2019/5/2
 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//value 硬币的价值
//n 待找零的钱
int coinChange(vector<int> &value, int n)
{
    int val_size = value.size();
    vector<vector<int>> dp(n + 1, vector<int>(val_size, n + 1));
    for (int i = 0; i < val_size; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < val_size; j++)
        {
            if (i >= value[j])
            {
                dp[i][j] = min(j - 1 >= 0 ? dp[i][j - 1] : n + 1, dp[i - value[j]][j] + 1);
            }
        }
    }
    return dp[n][val_size - 1] > n ? -1 : dp[n][val_size - 1];
}

int main()
{
    vector<int> value({1, 3, 4});
    int n = 6;
    cout << "coins: [";
    for (int i = 0; i < value.size() - 1; i++)
        cout << value[i] << ", ";
    cout << value.back() << "]" << endl;
    cout << "amount: " << n << endl;
    cout << "The minimum number of coins for change: " << coinChange(value, n) << endl;

    return 0;
}