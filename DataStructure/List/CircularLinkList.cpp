/**
 * 循环单链表
 * author 叶晨韬
 * date 2019/5/7
 **/
#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T info;
    Node<T> *next;
    Node<T>() : next(NULL) {}
    Node<T>(int x) : info(x), next(NULL) {}
};

template <class T>
class CircularLinkList
{
public:
    CircularLinkList();      //建立一个空的循环单链表
    ~CircularLinkList();     //析构函数
    Node<T> *rear();         //获得循环单链表的最后一个结点的存储位置
    void display();          //输出循环单链表中各个结点的值
    Node<T> *find(T x);      //在循环单链表中查找为x的结点
    void insert(T x, int i); //在循环单链表中第i个结点后插入一个值为x的新结点
    void dele(T x);          //在循环单链表中删除一值为x的结点
private:
    Node<T> *head;
};

template <typename T>
CircularLinkList<T>::CircularLinkList()
{
    head = NULL;
}

template <typename T>
CircularLinkList<T>::~CircularLinkList() {}

template <typename T>
Node<T> *CircularLinkList<T>::rear()
{
    Node<T> *p;
    if (!head) //循环单链表为空
        p = NULL;
    else
    {
        p = head;               //从第一个结点开始
        while (p->next != head) //没有到达最后一个结点
            p = p->next;        //继续向后
    }
    return p;
}

template <typename T>
void CircularLinkList<T>::display()
{
    Node<T> *p;
    if (!head)
        cout << "循环单链表是空的！" << endl;
    else
    {
        cout << "循环单链表各个结点的值分别为：";
        cout << head->info << " ";
        p = head->next;
        while (p != head) //没有回到第一个结点
        {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
    }
}

template <typename T>
Node<T> *CircularLinkList<T>::find(T x)
{
    Node<T> *q;
    if (!head)
    {
        cout << "循环单链表是空的！无法找到指定结点！" << endl;
        return NULL;
    }
    q = head;                               //q指向循环单链表的第一个结点，准备查找
    while (q->next != head && q->info != x) //没有查找到并且没有查找完整个表
        q = q->next;                        //继续查找
    if (q->info == x)
        return q;
    else
        return NULL;
}

template <typename T>
void CircularLinkList<T>::insert(T x, int i)
{
    Node<T> *p, *q, *myrear;
    int j;
    p = new Node<T>(x); //设置新结点的值
    if (i < 0)
    {
        cout << "无法找到指定插入的位置！" << endl;
        delete p;
        return;
    }
    if (i == 0 && !head) //插入前循环单链表如果是空的，则新结点的指针域应指向它自己
    { 
        p->next = p;
        head = p;
        return;
    }
    if (i == 0 && head) //在非空的循环单链表最前面插入
    {
        myrear = rear(head);
        p->next = head;
        head = p;
        myrear->next = p;
        return;
    }
    if (i > 0 && !head)
    {
        cout << "无法找到指定的插入位置！" << endl;
        delete p;
        return;
    }
    //在非空的循环单链表中插入值为x的结点，并且插入的结点不是第一个结点
    if (i > 0 && head)
    {
        q = head;                         //准备从表中第一个结点开始查找
        j = 1;                            //计数开始
        while (i != j && q->next != head) //没有找到并且没有找遍整个表
        {
            q = q->next;
            j++; //继续查找，计数器加1
        }
        if (i != j) //找不到指定插入位置，即i的值超过表中结点的个数，则不进行插入
        {
            cout << "表中不存在第" << i << "个结点，无法插入！" << endl;
            delete p;
            return;
        }
        else //找到了第i个结点，插入x
        {
            p->next = q->next;
            q->next = p;
            return;
        }
    }
}

template <typename T>
void CircularLinkList<T>::dele(T x)
{
    Node<T> *pre = NULL, *q;
    if (!head)
    {
        cout << "循环单链表为空，无法做删除操作！" << endl;
        return;
    }
    q = head;                               //从第一个结点开始准备查找
    while (q->next != head && q->info != x) //没有找遍整个表并且没有找到
    {
        pre = q;
        q = q->next;  //pre为q的前驱，继续查找
    }                 //循环结束后，pre为q的前驱
    if (q->info != x) //没找到
    {
        cout << "没有找到值为" << x << "的结点！" << endl;
    }
    else
    {
        if (q != head)
        {
            pre->next = q->next;
            delete q;
        }
        else
        {
            if (head == head->next)
            {
                delete q;
                head = NULL;
            }
            else
            {
                pre = head->next;
                while (pre->head != q)
                    pre = pre->next; //找q的前驱结点位置
                head = head->next;
                pre->next = head;
                delete q;
            }
        }
    }
}
