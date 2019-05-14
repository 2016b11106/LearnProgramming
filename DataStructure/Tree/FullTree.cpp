/**
 * 丰满树
 * author 叶晨韬
 * date 2019/5/12
 **/
#include <iostream>

/*设T是一棵二叉树，若定义nk是结点k到树根的路径长度，
若k(i)和k(j)是T中孩子结点个数少于2的任意结点，且满足：|nk(i)-nk(j)|<=1,
则称T是一颗丰满树。在丰满树中，子女结点个数少于2的结点只出现在树的最低两层*/
typedef int T;
struct Node
{
    T data;
    Node *lchild, *rchild;
};

//平分法创建一颗丰满树
//返回根节点
Node *createfulltree(T node[], int low, int high)
{
    int mid;
    Node *s;
    if (low <= high)
    {
        mid = (low + high) / 2;
        s = new Node();
        s->data = node[mid];
        s->lchild = createfulltree(node, low, mid - 1);
        s->rchild = createfulltree(node, mid + 1, high);
        return s;
    }
    else
        return NULL;
}
