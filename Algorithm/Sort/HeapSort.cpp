/**
 * 堆排序
 * author 叶晨韬
 * date 2019/4/26
 **/
#include <algorithm>

//默认省去数组的第一个数据
void heapSort(int *arr, int n)
{
    //先初始化最大堆
    for (int i = (n - 1) / 2; i >= 1; i--)
    {
        int k = i;
        while (2 * k < n) //若子节点指标在范围内才做比较
        {
            int j = 2 * k;
            //先比较两个子节点大小，选择最大的
            if (j + 1 < n && arr[j] < arr[j + 1])
                j = j + 1;
            if (arr[k] > arr[j]) //如果父节点大於子节点代表调整完毕，直接跳出函数
                break;
            std::swap(arr[k], arr[j]); //若孩子节点大于父节点，相互交换
            k = j;
        }
    }
    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = n - 1; i >= 1; i--)
    {
        std::swap(arr[1], arr[i]);
        int k = 1;
        while (2 * k < i)
        {
            int j = 2 * k;
            if (j + 1 < i && arr[j] < arr[j + 1])
                j = j + 1;
            if (arr[k] > arr[j])
                break;
            std::swap(arr[k], arr[j]);
            k = j;
        }
    }
}
