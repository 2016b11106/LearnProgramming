/**
 * 顺序循环队列
 * author 叶晨韬
 * date 2019/5/6
 **/
#include <iostream>
using namespace std;
const int max_size = 100;

template <class T>
class SequenceCircularQueue
{
  public:
    SequenceCircularQueue();          //顺序循环队列初始化
    ~SequenceCircularQueue();         //析构函数
    bool empty();                     //判断顺序循环队列是否为空
    void display();                   //打印顺序循环队列的结点值
    T get();                          //取得顺序循环队列的队首结点值
    void insert_sequence_cqueue(T x); //顺序循环队列的插入操作
    void dele_sequence_cqueue();      //顺序循环队列的删除操作
  private:
    T arr[max_size];
    int front;
    int rear;
};

template <typename T>
SequenceCircularQueue<T>::SequenceCircularQueue()
{
    front = rear = 0;
}

template <typename T>
SequenceCircularQueue<T>::~SequenceCircularQueue() {}

template <typename T>
bool SequenceCircularQueue<T>::empty()
{
    return front == rear;
}

template <typename T>
void SequenceCircularQueue<T>::display()
{
    if (empty())
    {
        cout << "顺序循环队列是空的！" << endl;
    }
    else
    {
        for (int i = front; i < rear; i++)
            cout << arr[i] << " " << endl;
    }
}

template <typename T>
T SequenceCircularQueue<T>::get()
{
    if (empty())
    {
        cout << "顺序循环队列是空的！无法获得队首结点值！" << endl;
        exit(1);
    }
    return arr[front];
}

template <typename T>
void SequenceCircularQueue<T>::insert_sequence_cqueue(T x)
{
    if ((rear + 1) % max_size == front)
    {
        cout << "顺序循环队列是满的！无法进行插入操作" << endl;
        exit(1);
    }
    arr[rear] = x;
    rear = (rear + 1) % max_size;
}

template <typename T>
void SequenceCircularQueue<T>::dele_sequence_cqueue()
{
    if (front == rear)
    {
        cout << "顺顺序循环队列空的！不能做删除操作！" << endl;
        exit(1);
    }
    front = (front + 1) % max_size;
};
