/**
 * 带头结点的单链表
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
    Node<T>() : next(NULL) {}
    Node<T>(int x) : info(x), next(NULL) {}
};

template <class T>
class HeadLinkList
{
public:
    HeadLinkList();          //建立一个空的带头结点的单链表s
    ~HeadLinkList();         //析构函数
    void display();          //输出带头结点的单链表中各个结点的值
    Node<T> *find(int i);    //在带头结点的单链表中查找第i个结点
    void insert(T x, int i); //在带头结点的单链表中第i个结点后插入一个值为x的新结点
    void dele(T x);          //在带头结点的单链表中删除一个值为x的结点
private:
    Node<T> *head;
};

template <typename T>
HeadLinkList<T>::HeadLinkList()
{
    head = new Node<T>();
}

template <typename T>
HeadLinkList<T>::~HeadLinkList() {}

template <typename T>
void HeadLinkList<T>::display()
{
    Node<T> *p = head->next; //从第一个（实际）结点开始
    if (!p)
    {
        cout << "带头结点的单链表是空的！" << endl;
    }
    else
    {
        cout << "带头结点的单链表各个结点的值为：" << endl;
        while (p)
        {
            cout << p->info << "->";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
}

template <typename T>
Node<T> *HeadLinkList<T>::find(int i)
{
    int j = 0;
    Node<T> *p = head;
    if (i < 0)
    {
        cout << "带头结点的单链表中不存在第" << i << "个结点！" << endl;
        return NULL;
    }
    else if (i == 0) //此时p指向的是头结点
        return p;
    while (p && i != j) //没有查找完并且还没有找到
    {
        p = p->next; //继续向后查找
        j++;         //计数器加1
    }
    return p; //返回结果，i=0时,p指向的是头结点
}

template <typename T>
void HeadLinkList<T>::insert(T x, int i)
{
    Node<T> *p, *q;
    /**
     * 查找带头结点的单链表中的第i个结点
     * i=0,表示新结点插入在头结点之后，此时p指向的是头结点
     **/
    q = find(i);
    if (!q)//没有找到
    { 
        cout << "带头结点的单链表中不存在第" << i << "个结点！不能插入" << x << "！" << endl;
    }
    else
    {
        p = new Node<T>(x);
        p->next = q->next;
        q->next = p;
    }
}

template <typename T>
void HeadLinkList<T>::dele(T x)
{
    Node<T> *pre = head, *q;  //首先pre指向头结点
    q = head->next;           //q从带头结点的第一个实际结点开始找值为x的结点
    while (q && q->info != x) //没有查找完并且还没有找到
    {
        pre = q; //继续查找，pre指向q的前驱
        q = q->next;
    }
    if (q)
    {
        pre->next = q->next; //删除
        delete q;            //释放空间
    }
}
