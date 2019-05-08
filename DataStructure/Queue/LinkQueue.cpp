/**
 * 链式队列
 * author 叶晨韬
 * date 2019/5/8
 **/
#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T info;
    Node<T> *next;
};

template <class T>
class LinkQueue
{
public:
    LinkQueue();      //建立一个空的链式队列
    ~LinkQueue();     //析构函数
    bool empty();     //判断队列是否为空
    void display();   //输出链式队列中各个结点的值
    T read();         //取得链式队列的队首结点值
    void insert(T x); //在链式队列中插入一个值为x的结点
    void dele();      //删除链式队列中队首结点
private:
    Node<T> *front, *rear;
};

template <typename T>
LinkQueue<T>::LinkQueue()
{
    front = rear = NULL;
}

template <typename T>
LinkQueue<T>::~LinkQueue() {}

template <typename T>
bool LinkQueue<T>::empty()
{
    return front ? false : true;
}

template <typename T>
void LinkQueue<T>::display()
{
    Node<T> *p = front;
    if (!p)
        cout << "链式队列是空的！" << endl;
    while (p)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

template <typename T>
T LinkQueue<T>::read()
{
    if (!front)
    {
        cout << "链式队列是空的！" << endl;
        exit(1);
    }
    return front->info;
}

template <typename T>
void LinkQueue<T>::insert(T x)
{
    Node<T> *p = new Node<T>();
    p->info = x;
    p->next = NULL;
    if (front == NULL) //当前队列为空，新插入的结点为队列中唯一一个结点
    {
        front = rear = p;
    }
    else
    {
        rear->next = p; //队尾插入
        rear = p;
    }
}

template <typename T>
void LinkQueue<T>::dele()
{
    Node<T> *q;
    if (!front)
    {
        cout << "队列为空，无法删除！" << endl;
        return;
    }
    q = front;       //q指向队首结点
    front = q->next; //队首指针指向下一个结点
    delete q;        //释放原队首结点空间
    if (front == NULL)
        rear = NULL; //队列中的唯一结点被删除后，队列变空
};
