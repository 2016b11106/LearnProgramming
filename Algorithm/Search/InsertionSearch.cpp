/**
 * 插值查找
 * author 叶晨韬
 * date 2019/4/29
 **/

int insertionSearch(int *arr, int n, int val)
{
    int lo = 0, hi = n - 1;
    while (lo < hi) //lo<=hi可能造成算术异常
    {
        int mid = lo + (val - arr[lo]) * (hi - lo) / (arr[hi] - arr[lo]);
        if (val < arr[mid])
            hi = mid - 1;
        else if (val > arr[mid])
            lo = mid + 1;
        else
            return mid;
    }
    return -1;
}
