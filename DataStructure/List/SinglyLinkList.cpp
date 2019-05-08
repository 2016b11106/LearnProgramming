/**
 * 单链表
 * author 叶晨韬
 * date 2019/5/6
 **/
#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T info;
    Node<T> *next;
    Node<T>(int x) : info(x), next(NULL) {}
};
template <class T>
class SinglyLinkList
{
public:
    SinglyLinkList();        //建立一个空的单链表
    ~SinglyLinkList();       //析构函数
    void display();          //输出单链表结点的值
    Node<T> *find(int i);    //在单链表中查找第i个结点
    void insert(T x, int i); //在单链表中第i个结点后插入一个值为x的新结点
    void dele(T x);          //在单链表中删除一个值为x的结点

private:
    Node<T> *head;
};

template <typename T>
SinglyLinkList<T>::SinglyLinkList()
{
    head = NULL;
}

template <typename T>
SinglyLinkList<T>::~SinglyLinkList() {}

template <typename T>
void SinglyLinkList<T>::display()
{
    Node<T> *p = head;
    if (!p)
    {
        cout << "单链表是空的！" << endl;
    }
    else
    {
        cout << "单链表结点的值为: ";
        while (p)
        {
            cout << p->info << "->";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
}

template <typename T>
Node<T> *SinglyLinkList<T>::find(int i)
{
    int j = 1;
    Node<T> *p = head;
    if (i < 1)
        return NULL;
    while (p && i != j)
    {
        p = p->next;
        j++;
    }
    return p;
}

template <typename T>
void SinglyLinkList<T>::insert(T x, int i)
{
    Node<T> *p, *q;
    q = find(i); //查找第i个结点
    if (!q && i != 0)
    {
        cout << "找不到第" << i << "个结点，不能插入" << x << "! " << endl;
    }
    else
    {
        p = new Node<T>(x);
        if (0 == i)
        { //插入的结点作为单链表的第一个结点
            p->next = head;
            head = p;
        }
        else
        {
            p->next = q->next;
            q->next = p;
        }
    }
}

template <typename T>
void SinglyLinkList<T>::dele(T x)
{
    Node<T> *pre = NULL, *p;
    if (!head)
    {
        cout << "单链表是空的！" << endl;
        return;
    }
    p = head;
    while (p && p->info != x)
    {
        pre = p; //pre指向p的前驱结点
        p = p->next;
    }
    if (p) //找到了被删除结点
    {
        if (!pre)
            head = head->next; //要删除的第一个结点
        else
            pre->next = p->next;
        delete p;
    }
    else
    {
        cout << "删除失败！无法找到值为" << x << "的结点" << endl;
    }
};
