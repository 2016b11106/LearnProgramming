/**
 * 平衡二叉排序树(AVL树)
 * author 叶晨韬
 * date 2019/5/12
 **/
#include <iostream>

/*平衡二叉树又称AVL树，它或者是一棵空树，或是具有下列性质的二叉树：它的左子树和右子树都是
平衡二叉树，且左子树和右子树高度之差的绝对值不超过1。*/
typedef int T;
struct Node
{
    T key;
    Node *lchild, *rchild;
    int bal; //结点的平衡度
};

//对AVL树进行左改组
void lchange(Node **t)
{
    Node *p1, *p2;
    p1 = (*t)->lchild;
    if (p1->bal == 1) //LL改组
    {
        (*t)->lchild = p1->rchild;
        p1->rchild = *t;
        (*t)->bal = 0;
        (*t) = p1;
    }
    else
    {
        p2 = p1->rchild;
        p1->rchild = p2->lchild;
        p2->lchild = p1;
        (*t)->lchild = p2->rchild;
        p2->rchild = *t;
        if (p2->bal == 1) //调整平衡度
        {
            (*t)->bal = -1;
            p1->bal = 0;
        }
        else
        {
            (*t)->bal = 0;
            p1->bal = 1;
        }
        (*t) = p2;
    }
    (*t)->bal = 0;
}

//对AVL树进行右改组
void rchange(Node **t)
{
    Node *p1, *p2;
    p1 = (*t)->rchild;
    if (p1->bal == -1) //RR改组
    {
        (*t)->rchild = p1->lchild;
        p1->lchild = *t;
        (*t)->bal = 0;
        (*t) = p1;
    }
    else //RL改组
    {
        p2 = p1->lchild;
        p1->lchild = p2->rchild;
        p2->rchild = p1;
        (*t)->rchild = p2->lchild;
        p2->lchild = (*t);
        if (p2->bal == -1) //调整平衡度
        {
            (*t)->bal = 1;
            p1->bal = 0;
        }
        else
        {
            (*t)->bal = 0;
            p1->bal = -1;
        }
        (*t) = p2;
    }
    (*t)->bal = 0;
}

//平衡二叉树的插入算法
//AVL树二级指针变量t;待插入结点值x;AVL树高度指针变量h
void InsertAVLTree(T x, Node **t, int *h)
{
    if (*t == NULL)
    {
        *t = new Node(); //生成根结点
        (*t)->key = x;
        (*t)->bal = 0;
        *h = 1;
        (*t)->lchild = (*t)->rchild = NULL;
    }
    else
    {
        if (x < (*t)->key)
        {
            InsertAVLTree(x, &(*t)->lchild, h);
            if (*h)
                switch ((*t)->bal)
                {
                case -1:
                    (*t)->bal = 0;
                    *h = 0;
                    break;
                case 0:
                    (*t)->bal = 1;
                    break;
                case 1:
                    /*进行左改组*/
                    lchange(t);
                    *h = 0;
                    break;
                }
        }
        else
        {
            if (x > (*t)->key)
            {
                InsertAVLTree(x, &(*t)->rchild, h);
                if (*h)
                    switch ((*t)->bal)
                    {
                    case 1:
                        (*t)->bal = 0;
                        *h = 0;
                        break;
                    case 0:
                        (*t)->bal = -1;
                        break;
                    case -1:
                        /*进行右改组*/
                        rchange(t);
                        *h = 0;
                        break;
                    }
            }
            else
                *h = 0;
        }
    }
}
