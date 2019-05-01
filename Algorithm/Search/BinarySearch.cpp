/**
 * 二分查找
 * author 叶晨韬
 * date 2019/4/29
 **/

int binarySearch(int *arr, int n, int val)
{
    int lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (val < arr[mid])
            hi = mid - 1;
        else if (val > arr[mid])
            lo = mid + 1;
        else
            return mid;
    }
    return -1;
}
