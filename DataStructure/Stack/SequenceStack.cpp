/**
 * 顺序栈
 * author 叶晨韬
 * date 2019/5/5
 **/
#include <iostream>
using namespace std;
const int max_size = 100; //定义顺序栈的最大长度

template <class T>
class SequenceStack
{
  public:
    SequenceStack();  //顺序栈初始化
    ~SequenceStack(); //析构函数
    bool empty();     //判断顺序栈栈是否为空
    T read();         //读顺序栈栈顶结点值
    void push(T x);   //顺序栈栈的插入操作
    void pop();       //顺序栈栈的删除操作
  private:
    T arr[max_size];
    int top;
};

template <typename T>
SequenceStack<T>::SequenceStack()
{
    top = 0;
}

template <typename T>
SequenceStack<T>::~SequenceStack() {}

template <typename T>
bool SequenceStack<T>::empty()
{
    return 0 == top;
}

template <typename T>
T SequenceStack<T>::read()
{
    if (empty())
    {
        cout << "栈是空的！" << endl;
        exit(1);
    }
    else
    {
        return arr[top - 1];
    }
}

template <typename T>
void SequenceStack<T>::push(T x)
{
    if (top == max_size)
    {
        cout << "栈是满的！" << endl;
        exit(1);
    }
    arr[top++] = x;
}

template <typename T>
void SequenceStack<T>::pop()
{
    if (0 == top)
    {
        cout << "栈的空的！" << endl;
        exit(1);
    }
    top--;
};
