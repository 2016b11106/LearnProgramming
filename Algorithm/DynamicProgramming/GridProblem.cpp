/**
 * m*n方格的走法(从左上角走到右下角)
 * author 叶晨韬
 * date 2019/5/6
 **/
#include <iostream>
#include <vector>
using namespace std;

int gridProblem(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }
    return dp[0][0];
}

int main()
{
    int m = 3, n = 3;
    cout << "m: " << m << endl;
    cout << "n: " << n << endl;
    cout << "The amount of moves: " << gridProblem(m, n) << endl;
    return 0;
}
