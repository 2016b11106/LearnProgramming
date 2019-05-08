/**
 * 链式栈
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
class LinkStack
{
public:
    LinkStack();    //建立一个空链式栈
    ~LinkStack();   //析构函数
    bool empty();   //判断链式栈是否为空
    T read();       //读链式栈的栈顶结点值
    void display(); //输出链式栈中各个结点的值
    void push(T x); //向链式栈中插入一个值为x的结点（进栈）
    void pop();     //删除链式栈的栈顶结点（出栈）
private:
    Node<T> *top;
};

template <typename T>
LinkStack<T>::LinkStack()
{
    top = NULL;
}

template <typename T>
LinkStack<T>::~LinkStack() {}

template <typename T>
bool LinkStack<T>::empty()
{
    return top ? false : true;
}

template <typename T>
T LinkStack<T>::read()
{
    if (!top)
    {
        cout << "链式栈是空的！" << endl;
        exit(1);
    }
    return top->info;
}

template <typename T>
void LinkStack<T>::display()
{
    Node<T> *p = top;
    if (!p)
        cout << "链式栈是空的！" << endl;
    while (p)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

template <typename T>
void LinkStack<T>::push(T x)
{
    Node<T> *p = new Node<T>();
    p->info = x;
    p->next = top;
    top = p;
}

template <typename T>
void LinkStack<T>::pop()
{
    Node<T> *q;
    if (!top)
    {
        cout << "链式栈是空的！" << endl;
        return;
    }
    q = top;         //指向被删除的结点
    top = top->next; //删除栈顶结点
    delete q;
};
