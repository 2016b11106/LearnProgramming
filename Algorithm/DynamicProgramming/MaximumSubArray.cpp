/**
 * 最大连续子序列和
 * author 叶晨韬
 * date 2019/5/5
 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxSubSum(vector<int> &arr)
{
    int res = arr[0], tmp = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        tmp = max(arr[i], tmp + arr[i]);
        res = max(tmp, res);
    }
    return res;
}

int main()
{
    vector<int> arr({2, -1, 5, 3, -10});
    cout << "arr: [";
    for (int i = 0; i < arr.size() - 1; i++)
        cout << arr[i] << ", ";
    cout << arr.back() << "]" << endl;
    cout << "MaxSubSum: " << MaxSubSum(arr) << endl;
    return 0;
}
