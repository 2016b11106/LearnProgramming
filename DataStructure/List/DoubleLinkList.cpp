/**
 * 双链表
 * author 叶晨韬
 * date 2019/5/7
 **/
#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T info;
    Node<T> *llink, *rlink;
};

template <class T>
class DoubleLinkList
{
public:
    DoubleLinkList();        //建立一个空的双链表
    ~DoubleLinkList();       //析构函数
    void display();          //输出双链表中各个结点的值
    Node<T> *find(int i);    //在双链表中查找第i个结点
    void insert(T x, int i); //在双链表中第i个结点后插入值为x的新结点
    void dele(T x);          //双链表删除一个值为x的结点
private:
    Node<T> *head;
};

template <typename T>
DoubleLinkList<T>::DoubleLinkList()
{
    head = NULL;
}

template <typename T>
DoubleLinkList<T>::~DoubleLinkList() {}

template <typename T>
void DoubleLinkList<T>::display()
{
    Node<T> *p = head;
    if (!p)
        cout << "双链表是空的！" << endl;
    else
    {
        cout << "双链表中各个结点的值为：";
        while (p)
        {
            cout << p->info << " ";
            p = p->rlink;
        }
        cout << endl;
    }
}

template <typename T>
Node<T> *DoubleLinkList<T>::find(int i)
{
    int j = 1;
    Node<T> *p = head;
    if (i < 1)
    {
        cout << "第" << i << "个结点不存在！" << endl;
        return NULL;
    }
    while (p && i != j) //没有找到整个表并且没有找到
    {
        p = p->rlink; //继续沿着右指针向后查找
        j++;          //计数器加1
    }
    if (!p)
    {
        cout << "第" << i << "个结点不存在！" << endl;
        return NULL;
    }
    return p;
}

template <typename T>
void DoubleLinkList<T>::insert(T x, int i)
{
    Node<T> *p, *q;
    p = new Node<T>(); //分配空间
    p->info = x;       //设置新结点的值
    if (i == 0)        //在最前面插入一个值为x的新结点
    {
        p->llink = NULL; //新插入的结点没有前驱
        p->rlink = head; //新插入的结点的后继是原来双链表中的第一个结点
        if (!head)       //原表为空
        {
            head = p;
        }
        else
        {
            head->llink = p; //原来双链表中第一个结点的前驱是新插入的结点
            head = p;        //新结点成为双链表的第一个结点
        }
        return;
    }
    q = find(i); //查找第i个结点
    if (!q)      //第i个结点不存在
    {
        cout << "第" << i << "个结点不存在，无法进行插入！" << endl;
        delete p;
        return;
    }
    if (q->rlink == NULL) //在最后一个结点后插入
    {
        p->rlink = q->rlink; //即为NULL,新插入的结点没有后继
        p->llink = q;
        q->rlink = p;
    }
    else //一般情况的插入
    {
        p->rlink = q->rlink;
        p->llink = q;
        q->rlink->llink = p;
        q->rlink = p;
    }
    return;
}

template <typename T>
void DoubleLinkList<T>::dele(T x)
{
    Node<T> *q;
    if (!head) //双链表为空，无法进行删除操作
    {
        cout << "双链表为空！无法进行删除操作！" << endl;
        return;
    }
    q = head;
    while (q && q->info != x)
        q = q->rlink; //循环结束后q指向的是值为x的结点
    if (!q)
    {
        cout << "没有找到值为" << x << "的结点！不能做删除操作" << endl;
    }
    if (q == head && head->rlink) //被删除的结点是第一个结点并且表中不只一个结点
    {
        head = head->rlink;
        head->llink = NULL;
        delete q;
        return;
    }
    if (q == head && !head->rlink) //被删除的结点是第一个结点并且表中只有者一个结点
    {
        delete q;
        head = NULL; //双链表置空
        return;
    }
    else
    {
        if (!q->rlink) //被删除的结点是双链表中的最后一个结点
        {
            q->llink->rlink = NULL;
            delete q;
            return;
        }
        else //q是有2个以上结点的双链表中的一个非开始，也非终端结点
        {
            q->llink->rlink = q->rlink;
            q->rlink->llink = q->llink;
            delete q;
            return;
        }
    }
};
