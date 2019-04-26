/**
 * 归并排序
 * author 叶晨韬
 * date 2019/4/24
 **/
#include <algorithm>

int aux[100];
void merge(int *arr, int lo, int hi)
{
    for (int i = lo; i <= hi; i++)
        aux[i] = arr[i];
    int mid = lo + (hi - lo) / 2;
    int k = lo, tmp = mid + 1;
    while (k <= hi)
    {
        if (lo >= mid + 1)
            arr[k++] = aux[tmp++];
        else if (tmp > hi)
            arr[k++] = aux[lo++];
        else if (aux[lo] > aux[tmp])
            arr[k++] = aux[tmp++];
        else
            arr[k++] = aux[lo++];
    }
}

void _mergeSort(int *arr, int lo, int hi)
{
    if (lo >= hi)
        return;
    int mid = lo + (hi - lo) / 2;
    _mergeSort(arr, lo, mid);     //左边归并排序，使得左子序列有序
    _mergeSort(arr, mid + 1, hi); //右边归并排序，使得右子序列有序
    merge(arr, lo, hi);           //将两个有序子数组合并操作
}

void mergeSort(int *arr, int n)
{
    _mergeSort(arr, 0, n - 1);
}

/**
 * 归并排序(自底向上)
 **/
void mergeSort2(int *arr, int n)
{
    //i表示归并子数组的长度，1表示，一个一个的归并，
    //归并后的长度为2,2表示两个两个的归并，归并后的长度为4,以此类推
    for (int i = 1; i < n; i *= 2)
    {
        for (int j = 0; j < n; j += (i * 2))
        {
            int lo = j, hi = std::min(j + (i * 2) - 1, n - 1); //数组长度不满足2的x次幂的数组,可能造成越界
            for (int l = lo; l <= hi; l++)
                aux[l] = arr[l];
            int mid = j + i - 1; //mid取左半部分的最后一个值
            int k = lo, tmp = mid + 1;
            while (k <= hi)
            {
                if (lo >= mid + 1)
                    arr[k++] = aux[tmp++];
                else if (tmp > hi)
                    arr[k++] = aux[lo++];
                else if (aux[lo] < aux[tmp])
                    arr[k++] = aux[lo++];
                else
                    arr[k++] = aux[tmp++];
            }
        }
    }
}
