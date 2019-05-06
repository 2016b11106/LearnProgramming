/**
 * 数字三角形
 * author 叶晨韬
 * date 2019/5/2
 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int digitalTriangle(vector<vector<int>> &v)
{
    for (int i = v.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            v[i][j] = max(v[i + 1][j], v[i + 1][j + 1]) + v[i][j];
        }
    }
    return v[0][0];
}

int main()
{
    vector<vector<int>> v({{13, 0, 0, 0, 0},
                           {11, 8, 0, 0, 0},
                           {12, 7, 26, 0, 0},
                           {6, 14, 15, 8, 0},
                           {12, 7, 13, 24, 11}});
    for (unsigned int i = 0; i < v.size(); i++)
    {
        for (unsigned int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == 0)
                continue;
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The longest path from bottom to top: " << digitalTriangle(v) << endl;

    return 0;
}
