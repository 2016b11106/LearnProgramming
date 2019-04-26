/**
 * 插入排序
 * author 叶晨韬
 * date 2019/4/24
 **/

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int pivot = arr[i];
        int j = i;
        for (; j >= 1 && arr[j - 1] > pivot; j--)
            arr[j] = arr[j - 1]; //后一个覆盖前一个的值
        arr[j] = pivot;          //在要插入的位置赋值
    }
}
