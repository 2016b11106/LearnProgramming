/**
 * 顺序队列
 * author 叶晨韬
 * date 2019/5/5
 **/
#include <iostream>
using namespace std;
const int max_size = 100;

template <class T>
class SequenceQueue
{
  public:
    SequenceQueue();  //顺序队列初始化
    ~SequenceQueue(); //析构函数
    bool empty();     //判断顺序队列是否为空
    void display();   //打印顺序队列的结点值
    T get();          //取得顺序队列的队首结点值
    void insert(T x); //顺序队列的插入操作
    void dele();      //顺序队列的删除操作
  private:
    T arr[max_size];
    int front;
    int rear;
};

template <typename T>
SequenceQueue<T>::SequenceQueue()
{
    front = rear = 0;
}

template <typename T>
SequenceQueue<T>::~SequenceQueue() {}

template <typename T>
bool SequenceQueue<T>::empty()
{
    return front == rear;
}

template <typename T>
void SequenceQueue<T>::display()
{
    if (empty())
    {
        cout << "顺序队列是空的！" << endl;
    }
    else
    {
        for (int i = front; i < rear; i++)
            cout << arr[i] << " " << endl;
    }
}

template <typename T>
T SequenceQueue<T>::get()
{
    if (empty())
    {
        cout << "顺序队列是空的！无法获得队首结点值！" << endl;
        exit(1);
    }
    return arr[front];
}

template <typename T>
void SequenceQueue<T>::insert(T x)
{
    if (rear == max_size)
    {
        cout << "顺序队列是满的！" << endl;
        exit(1);
    }
    arr[rear++] = x;
}

template <typename T>
void SequenceQueue<T>::dele()
{
    if (front == rear)
    {
        cout << "顺序队列是空的！不能做删除操作！" << endl;
        exit(1);
    }
    front++;
};
