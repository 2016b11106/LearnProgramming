/**
 * 冒泡排序
 * author 叶晨韬
 * date 2019/4/24
 **/
#include <algorithm>

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

/**
 * 冒泡排序的第一个优化
 **/
void bubbleSort2(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false; //设置一个标记
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag) //flag为false表示这一趟没有数据进行交换，表明数组已经有序，不需要再进行排序
            return;
    }
}

/**
 * 冒泡排序的第二个优化
**/
void bubbleSort3(int *arr, int n)
{
    int pos = n - 1;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        int k = pos;
        for (int j = 0; j < k; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                flag = true;
                pos = j; //记录最后一次交换数据的位置
            }
        }
        if (!flag)
            return;
        k = pos; //pos位置后面的数据已经全部排好序了
    }
}
