/**
 * 顺序查找
 * author 叶晨韬
 * date 2019/4/29
 **/

int sequenceSearch(int *arr, int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;
}
