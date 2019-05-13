/**
 * 大根堆
 * author 叶晨韬
 * date 2019/5/8
 **/
#include <iostream>
#include <algorithm>
using namespace std;
const int max_size = 100; //定义堆底层数组的最大长度

template <class T>
class MaxHeap
{
public:
    MaxHeap();                   //初始化建议一个大根堆
    ~MaxHeap();                  //析构函数
    bool empty();                //判断大根堆是否为空
    void display();              //从上到下，从左到右依次打印大根堆结点的值
    void heapify(int *a, int n); //堆化（传入数组，构建大根堆）
    T read();                    //读取大根堆堆顶元素的值
    void insert(T x);            //向大根堆中插入一个值为x的结点
    void pop();                  //删除大根堆中堆顶结点
private:
    void sink(int i);  //堆结点的下沉
    void raise(int i); //堆结点的上浮
    int arr[max_size]; //从下标1开始
    int size;
};

template <typename T>
MaxHeap<T>::MaxHeap()
{
    size = 1; //下标从1开始，便于计算
}

template <typename T>
MaxHeap<T>::~MaxHeap() {}

template <typename T>
bool MaxHeap<T>::empty()
{
    return 1 == size ? true : false;
}

template <typename T>
void MaxHeap<T>::display()
{
    if (size == 1)
    {
        cout << "大根堆是空的！" << endl;
        return;
    }
    //size指向最后一个元素下标值的下一个
    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void MaxHeap<T>::heapify(int *a, int n)
{
    if (size > 1)
    {
        cout << "大根堆里存在元素，无法完成堆化！" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i + 1] = a[i]; //传入数组的元素赋值给堆数组
    }
    size = n + 1;
    for (int i = (size - 1) / 2; i >= 1; i--)
    {
        sink(i); //执行下沉操作
    }
}

template <typename T>
T MaxHeap<T>::read()
{
    if (size == 1)
    {
        cout << "大根堆是空的！" << endl;
        exit(1);
    }
    return arr[1];
}

template <typename T>
void MaxHeap<T>::insert(T x)
{
    if (size == max_size)
    {
        cout << "堆已经满了！无法插入！" << endl;
        return;
    }
    arr[size++] = x;
    raise(size - 1); //最后一个元素执行上浮操作
}

template <typename T>
void MaxHeap<T>::pop()
{
    swap(arr[1], arr[size - 1]); //堆顶结点与最后一个结点交换
    size--;
    sink(1); //堆顶结点下沉，维持大根堆形态
}

template <typename T>
void MaxHeap<T>::sink(int i)
{
    int k = i;
    while (2 * k <= (size - 1))
    {
        int j = 2 * k;                           //左孩子结点的下标
        if (j + 1 < size && arr[j + 1] > arr[j]) //得到左右孩子中最大的孩子
            j = j + 1;
        if (arr[k] >= arr[j]) //父结点大于左右孩子结点的最大值
            break;            //退出循环
        swap(arr[j], arr[k]); //交换结点
        k = j;
    }
}

template <typename T>
void MaxHeap<T>::raise(int i)
{
    int k = i;
    while (k / 2 >= 1)
    {
        int j = k / 2;        //父结点的下标
        if (arr[j] >= arr[k]) //父结点大于此结点，退出循环
            break;
        swap(arr[j], arr[k]); //交换
        k = j;
    }
}
