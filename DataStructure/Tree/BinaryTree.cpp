/**
 * 二叉树
 * author 叶晨韬
 * date 2019/5/9
 **/
#include <iostream>
#include <stack>
using namespace std;

/*链式存储下二叉树结点数据结构的定义*/
typedef char T;
struct Node
{
    T data;
    Node *lchild, *rchild;
};

/*以下的算法基于二叉树的代码实现*/
Node *createbinarytree(const T *c, int *i); //二叉树的创建算法
void preorder(Node *root);                  //前序遍历二叉树的递归算法
void inorder(Node *root);                   //中序遍历二叉树的递归算法
void postorder(Node *root);                 //后序遍历二叉树的递归算法
void preorder1(Node *root);                 //二叉树前序遍历的非递归实现
void inorder1(Node *root);                  //二叉树中序遍历的非递归实现
Node *locate(Node *root, T x);              //二叉树的查找算法
int numofnode(Node *root);                  //统计二叉树的结点数
bool isequal(Node *root1, Node *root2);     //判断两棵二叉树是否等价
int depth(Node *root);                      //求二叉树的高度

//返回二叉树的根节点
//使用createbinarytree建立一颗给定的二叉树是，必须按其前序遍历遍历的顺序输入结点的值
//遍历过程中遇到空子树时，必须使用‘#’代替
//结点序列如：abd#e##fg###c##
Node *createbinarytree(const T *c, int *i)
{
    Node *t;
    T ch = c[*i];
    *i += 1;
    if (ch == '#')
        return NULL;
    else
    {
        t = new Node();
        t->data = ch;
        t->lchild = createbinarytree(c, i);
        t->rchild = createbinarytree(c, i);
    }
    return t;
}

void preorder(Node *root)
{
    if (root)
    {
        cout << root->data;
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->lchild);
        cout << root->data;
        inorder(root->rchild);
    }
}

void postorder(Node *root)
{
    if (root)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        cout << root->data;
    }
}

void preorder1(Node *root)
{
    stack<Node *> s;
    while (!s.empty() || root)
    {
        if (root)
        {
            cout << root->data;
            s.push(root);
            root = root->lchild;
        }
        else
        {
            Node *tmp = s.top();
            s.pop();
            root = tmp->rchild;
        }
    }
}

void inorder1(Node *root)
{
    stack<Node *> s;
    while (!s.empty() || root)
    {
        while (root)
        {
            s.push(root);
            root = root->lchild;
        }
        Node *tmp = s.top();
        s.pop();
        cout << tmp->data;
        if (tmp->rchild)
            root = tmp->rchild;
    }
}

Node *locate(Node *root, T x)
{
    Node *p;
    if (root == NULL)
        return NULL;
    else
    {
        if (root->data == x)
            return root;
        else
        {
            p = locate(root->lchild, x);
            if (p)
                return p;
            else
                return locate(root->rchild, x);
        }
    }
}

int numofnode(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return (numofnode(root->lchild) + numofnode(root->rchild) + 1);
}

bool isequal(Node *root1, Node *root2)
{
    bool t = false;
    if (root1 == NULL && root2 == NULL) //root1和root2均为空，则二者等价
        return true;
    else
    {
        if (root1 != NULL && root1 != NULL)                //处理root1和root2均不为空的情形
            if (root1->data == root2->data)                //如果根结点的值相等
                if (isequal(root1->lchild, root2->lchild)) //如果root1和root2的左子树等价
                    //返回值取决于root1和root2的右子树是否等价
                    t = isequal(root1->rchild, root2->rchild);
    }
    return t;
}

int depth(Node *root)
{
    int h, lh, rh;
    if (root == NULL) //处理空二叉树的情况
        h = 0;
    else
    {
        lh = depth(root->lchild); //求左子树的高度
        rh = depth(root->rchild); //求右子树的高度
        /*求二叉树的高度*/
        if (lh >= rh)
            h = lh + 1;
        else
            h = rh + 1;
    }
    return h;
}

int main()
{
    int i = 0;
    Node *root = createbinarytree("abd#e##fg###c##", &i);
    cout << "创建了结点序列为abd#e##fg###c##的二叉树" << endl;
    cout << "前序遍历：";
    preorder1(root);
    cout << endl;
    cout << "中序遍历：";
    inorder1(root);
    cout << endl;
    cout << "后序遍历：";
    postorder(root);
    cout << endl;
    T x = 'c';
    cout << "值为" << x << "的二叉树结点的位置：" << locate(root, x) << endl;
    cout << "二叉树中结点的个数：" << numofnode(root) << endl;
    cout << "二叉树的高度：" << depth(root) << endl;
    return 0;
}
