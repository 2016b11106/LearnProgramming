/**
 * 哈夫曼树
 * author 叶晨韬
 * date 2019/5/13
 **/
#include <iostream>

/*具有最小带权外部路径长度的二叉树称为Huffman树*/
struct Node //huffman树存储结构
{
    int data; //权值
    Node *lchild, *rchild, *next;
};

//将新结点s插入到有序链表root中，并保持链表的有序性
//返回链表头结点指针root
Node *insert(Node *root, Node *s)
{
    Node *p1, *p2;
    if (root == NULL)
        root = s;
    else
    {
        p1 = NULL;
        p2 = root;
        while (p2 && p2->data < s->data)
        {
            p1 = p2;
            p2 = p2->next;
        }
        s->next = p2;
        if (p1 == NULL)
            root = s;
        else
            p1->next = s;
    }
    return root;
}

//根据有序链表root建立huffman树
void createhuffman(Node **root)
{
    Node *s, *rl, *rr;
    while (*root && (*root)->next)
    {
        rl = *root; //每次从链表头部取下两结点作为新生成结点的左、右子树
        rr = (*root)->next;
        *root = rr->next;
        s = new Node(); //生成新结点
        s->next = NULL;
        s->data = rl->data + rr->data;
        s->lchild = rl;
        s->rchild = rr;
        rl->next = rr->next = NULL;
        *root = insert(*root, s); //将新结点插入到有序表root中
    }
}
