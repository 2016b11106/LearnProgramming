/**
 * 斐波那契查找
 * author 叶晨韬
 * date 2019/5/1
 **/
#include <memory>
const int max_size = 20; //斐波那契数组的长度

//构建斐波那契数组
void fibonacciArray(int *F)
{
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < max_size; i++)
        F[i] = F[i - 1] + F[i - 2];
}

int fibonacciSearch(int *arr, int n, int val)
{
    int F[max_size];
    fibonacciArray(F);
    int k = 0;
    while (n > F[k] - 1) //计算n位于斐波那契数列的位置
        k++;
    int *temp = new int[F[k] - 1]; //将数组扩展到F[k]-1的长度
    memcpy(temp, arr, n * sizeof(int));
    for (int i = n; i < F[k] - 1; i++)
        temp[i] = arr[n - 1];

    int lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        int mid = lo + F[k - 1] - 1;
        if (val < temp[mid])
        {
            k -= 1;
            hi = mid - 1;
        }
        else if (val > temp[mid])
        {
            k -= 2;
            lo = mid + 1;
        }
        else
        {
            if (mid < n)
                return mid; //若相等则说明mid即为查找到的位置
            else
                return n - 1; //若mid>=n则说明是扩展的数值,返回n-1
        }
    }
    delete[] temp;
    return -1;
}
