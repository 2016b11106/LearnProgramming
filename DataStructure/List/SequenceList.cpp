/**
 * 顺序表表
 * author 叶晨韬
 * date 2019/5/5
 **/
#include <iostream>
using namespace std;
const int max_size = 100;

template <class T>
class SequenceList
{
  public:
    SequenceList();                 //顺序表的初始化
    ~SequenceList();                //析构函数
    void append(T x);               //在顺序表后部插入值为x的结点
    void display();                 //打印顺序表的各结点值
    bool empty();                   //判断顺序表是否为空
    int find(T x);                  //查找顺序表中值为x的结点位置
    T get(int i);                   //取得顺序表中的第i个结点的值
    void insert(int position, T x); //在顺序表的position位置插入值为x的结点
    void dele(int position);        //删除表中第position位置的结点
  private:
    T arr[max_size];
    int size;
};
template <typename T>
SequenceList<T>::SequenceList()
{
    size = 0;
}

template <typename T>
SequenceList<T>::~SequenceList() {}

template <typename T>
void SequenceList<T>::append(T x)
{
    if (size == max_size)
    {
        cout << "顺序表是满的！" << endl;
        return;
    }
    arr[size++] = x;
}

template <typename T>
void SequenceList<T>::display()
{
    if (0 == size)
        cout << "顺序表是空的！" << endl;
    else
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

template <typename T>
bool SequenceList<T>::empty()
{
    return 0 == size;
}

template <typename T>
int SequenceList<T>::find(T x)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

template <typename T>
T SequenceList<T>::get(int i)
{
    if (i < 0 || i >= size)
    {
        cout << "指定位置的结点不存在！" << endl;
        exit(1);
    }
    else
    {
        return arr[i];
    }
}

template <typename T>
void SequenceList<T>::insert(int position, T x)
{
    if (max_size == size)
    {
        cout << "顺序表是满的！没法插入！" << endl;
        exit(1);
    }
    if (position < 0 || position > size)
    {
        cout << "指定的插入位置不存在！" << endl;
        exit(1);
    }
    for (int i = size; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = x;
    size++;
}

template <typename T>
void SequenceList<T>::dele(int position)
{
    if (0 == size)
    {
        cout << "顺序表是空的！" << endl;
        exit(1);
    }
    if (position < 0 || position >= size)
    {
        cout << "指定的删除位置不存在！" << endl;
        exit(1);
    }
    for (int i = position; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
};
