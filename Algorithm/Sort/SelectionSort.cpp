/**
 * 选择排序 
 * author 叶晨韬 
 * date 2019/4/24
 **/
#include <algorithm>

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j; //更新最小值的下标
        }
        if (k != i)
            std::swap(arr[i], arr[k]);
    }
}

/**
 * 选择排序的优化(一次将两个元素放在它的最终位置上）
 **/
void selectionSort2(int *arr, int n)
{
    int lo = 0, hi = n - 1;
    while (lo < hi)
    {
        int max_k = lo, min_k = lo;
        for (int i = lo; i <= hi; i++)
        {
            if (arr[i] > arr[max_k])
                max_k = i;
            if (arr[i] < arr[min_k])
                min_k = i;
        }
        if (max_k != hi) //将最大值插到最后
            std::swap(arr[max_k], arr[hi]);
        if (min_k == hi) //防止minpos在最大值要插入的位置
            min_k = max_k;
        if (min_k != lo) //将最小值插到最前面
            std::swap(arr[min_k], arr[lo]);
        lo++;
        hi--;
    }
}
