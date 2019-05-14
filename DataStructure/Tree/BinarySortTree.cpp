/**
 * 二叉排序树
 * author 叶晨韬
 * date 2019/5/11
 **/
#include <iostream>
using namespace std;

/*二叉排序树不仅具有二分检索的效率，同时又便于在查找表中进行数据的增添与删除操作*/
//二叉排序树又称为二叉查找树，它或者是空树，或者是满足如下性质的二叉树
//1.若它的左子树非空，则左子树上所有结点的值均小于根结点的值
//2.若它的右子树非空，则右子树上所有结点的值均大于根结点的值
//3.若它的左、右子树本身又各是一棵二叉排序树
typedef int T;
struct Node //二叉排序树结点定义
{
    T key;                 //结点值
    Node *lchild, *rchild; //左、右孩子指针
};

class BST
{
public:
    BST();                  //初始化一棵二叉排序树
    ~BST();                 //析构函数
    void CreateBstree();    //建立一棵二叉排序树
    void InsertBstree(T x); //基于二叉排序树的结点的插入算法
    Node *search1(T x);     //二叉排序树的查找算法
    Node *search2(T x);     //二叉排序树的递归查找算法
    void DelBstree(T x);    //基于二叉排序树的结点删除
private:
    Node *_search2(Node *root, T x); //二叉排序树的递归查找算法(辅助函数)
    //p返回待查结点x在二叉排序树中的地址，f返回待查结点x的父结点地址
    void Delsearch(T x, Node **f, Node **q); //DelBstree删除函数里的辅助查找函数
    Node *root;
};

BST::BST()
{
    root = NULL;
}

BST::~BST() {}

void BST::CreateBstree()
{
    T key;
    cout << "请输入一个以-1结束标记的结点序列；" << endl;
    cin >> key;
    while (key != -1)
    {
        InsertBstree(key);
        cin >> key;
    }
}

void BST::InsertBstree(T x)
{
    Node *p, *f = NULL;
    p = root;
    while (p) //查找插入位置
    {
        if (x == p->key) //若二叉排序树中已有key,则无需插入
            return;
        f = p; //f用于保存新结点的最终插入位置
        p = (x < p->key) ? p->lchild : p->rchild;
    }
    p = new Node(); //生成待插入的新结点
    p->key = x;
    p->lchild = p->rchild = NULL;
    if (root == NULL) //原树为空
        root = p;
    else
    {
        if (x < f->key)
            f->lchild = p;
        else
            f->rchild = p;
    }
}

//1.当二叉树为空树，检索失败
//2.如果二叉排序树根结点的关键字等于待检索的关键字，则检索成功
//3.如果二叉排序树根节点的关键字小于待检索的关键字，则用相同的方法继续在根结点的右子树中检索
//4.如果二叉排序树根节点的关键字大于待检索的关键字，则用相同的方法继续在根结点的左子树中检索
Node *BST::search1(T x)
{
    Node *p = root;
    while (p)
    {
        if (x == p->key)
            return p;
        p = x < p->key ? p->lchild : p->rchild;
    }
    return NULL;
}

Node *BST::search2(T x)
{
    return _search2(root, x);
}

Node *BST::_search2(Node *root, T x)
{
    if (root == NULL || x == root->key)
        return root;
    if (x < root->key)
        return _search2(root->lchild, x);
    else
        return _search2(root->rchild, x);
}

void BST::DelBstree(T x)
{
    Node *p, *q, *child;
    Delsearch(x, &p, &q); //查找被删结点
    if (q)                //找到了待删除结点
    {
        if (q->lchild == NULL && q->rchild == NULL) //情况1，被删结点为叶节点
        {
            if (p) //待删结点有双亲
            {
                if (p->lchild == q)
                    p->lchild = NULL;
                else
                    p->rchild = NULL;
            }
            else //被删结点为树根
                root = NULL;
            delete q;
        }
        else
        {
            if (q->rchild == NULL) //情况2，被删结点的右子树为空，用被删结点的左子树替代该结点
            {
                if (p) //被删结点的双亲结点不为空
                {
                    if (p->lchild == q)
                        p->lchild = q->lchild; //q是其双亲结点的左儿子
                    else
                        p->rchild = q->lchild; //q是其双亲结点的右儿子
                }
                else
                {
                    root = q->lchild;
                }
                delete q;
            }
            else
            {
                if (q->lchild == NULL) //情况3，被删结点的左子树为空，用被删结点的右子树替代该结点
                {
                    if (p) //被删结点的双亲结点不为空
                    {
                        if (p->lchild == q)
                            p->lchild = q->rchild; //q是其双亲结点的左儿子
                        else
                            p->rchild = q->rchild; //q是其双亲结点的右儿子
                    }
                    else
                    {
                        root = q->rchild;
                    }
                    delete q;
                }
                /*情况4，被删结点的左右子树均不为空，用右子树代替被删结点，同时将被删结点的左子树
                收为右子树中序首点的左儿子*/
                else
                {
                    child = q->rchild;
                    while (child->lchild) //找被删结点右子树的中序首点
                    {
                        child = child->lchild;
                    }
                    child->lchild = q->lchild; //收被删结点的左子树收为child的左孩子
                    if (p)                     //被删结点不是树根
                    {
                        if (p->lchild == q)
                            p->lchild = q->rchild;
                        else
                            p->rchild = q->rchild;
                    }
                    else //被删结点是树根
                    {
                        root = q->rchild;
                    }
                    delete q;
                }
            }
        }
    }
    return;
}

//*p返回待查结点x在二叉排序树中的地址，*f返回待查结点x的父结点的地址
void BST::Delsearch(T x, Node **f, Node **p)
{
    *f = NULL;
    *p = root;
    while (*p)
    {
        if (x == (*p)->key)
            return;
        *f = *p;
        *p = (x < (*p)->key) ? (*p)->lchild : (*p)->rchild;
    }
    return;
}
