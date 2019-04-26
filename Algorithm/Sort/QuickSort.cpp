/**
 * 快速排序
 * author 叶晨韬
 * date 2019/4/26
 **/
#include <iostream>

void _quickSort(int *arr, int lo, int hi)
{
    if (lo >= hi)
        return;
    int pivot = arr[lo]; // 基准数据
    int i = lo, j = hi;
    while (i < j)
    {
        // 当队尾的元素大于等于基准数据时,向前挪动j指针
        while (i < j && arr[j] >= pivot)
            j--;
        // 如果队尾元素小于pivot了,需要将其赋值给i
        if (i < j)
        {
            arr[i] = arr[j];
            i++;
        }
        //当队首元素小于等于pivot时,向前挪动i指针
        while (i < j && arr[i] <= pivot)
            i++;
        // 当队首元素大于pivot时,需要将其赋值给j
        if (i < j)
        {
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = pivot;             //基准赋值到i位置上
    _quickSort(arr, lo, i - 1); //递归左边
    _quickSort(arr, i + 1, hi); //递归右边
}

void quickSort(int *arr, int n)
{
    _quickSort(arr, 0, n - 1);
}
