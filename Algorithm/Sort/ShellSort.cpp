/**
 * 希尔排序
 * author 叶晨韬
 * date 2019/4/24
 **/

void shellSort(int *arr, int n)
{
    int k = n / 2; //增量k
    while (k != 0) //当k==1时，数组近乎有序，大大提高插入排序的效率
    {
        //在其所在组进行插入排序
        for (int i = 0; i < n; i++)
        {
            int pivot = arr[i];
            int j = i;
            for (; j >= k && arr[j - k] > pivot; j -= k)
                arr[j] = arr[j - k];
            arr[j] = pivot;
        }
        k /= 2; //逐步缩小增量
    }
}
