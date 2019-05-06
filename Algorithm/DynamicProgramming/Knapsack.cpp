/**
 * 背包问题
 * author 叶晨韬
 * date 2019/5/4
 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//weight 物品重量
//value  物品价值
//capacity 背包容量
int knapsack01(vector<int> &weight, vector<int> &value, int capacity)
{
    int n = weight.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= capacity; i++)
        dp[0][i] = weight[0] <= i ? value[0] : 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], dp[i - 1][j]);
        }
    }
    return dp[n - 1][capacity];
}

int main()
{
    vector<int> weight({1, 3, 6});
    vector<int> value({2, 5, 6});
    int capacity = 6;
    cout << "weight: [";
    for (int i = 0; i < weight.size() - 1; i++)
        cout << weight[i] << ", ";
    cout << weight.back() << "]" << endl;
    cout << "value: [";
    for (int i = 0; i < value.size() - 1; i++)
        cout << value[i] << ", ";
    cout << value.back() << "]" << endl;
    cout << "backpack capacity: " << capacity << endl;
    cout << "Total value of backpack: " << knapsack01(weight, value, capacity) << endl;
    return 0;
}
