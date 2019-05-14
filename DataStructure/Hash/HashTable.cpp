/**
 * 散列表
 * author 叶晨韬
 * date 2019/5/13
 **/
#include <iostream>

/*运用除余法构造散列函数并用拉链法解决地址冲突的散列表构造及检索算法*/
const int Hashmax = 5;
class HashTable
{
public:
    HashTable();               //初始化散列表
    ~HashTable();              //析构函数
    int hash_mod(int key);     //求余法散列函数
    void insert_hash(int key); //散列表插入运算
    bool hash_search(int key); //基于Hash链表的查找
private:
    struct Node //声明列表结构
    {
        int key; //键值
        Node *next;
    };
    Node *hashtab[Hashmax]; //Hash链表表头指针数组
};

HashTable::HashTable() {}

HashTable::~HashTable() {}

int HashTable::hash_mod(int key)
{
    return key % Hashmax;
}

void HashTable::insert_hash(int key)
{
    Node *newNode;
    int index;
    newNode = new Node(); //生成新结点
    newNode->key = key;
    newNode->next = NULL;
    index = hash_mod(key);
    newNode->next = hashtab[index]; //插入到所在的链表表头
    hashtab[index] = newNode;
}

bool HashTable::hash_search(int key)
{
    Node *p;
    int index;
    index = hash_mod(key); //取得数据位置
    p = hashtab[index];    //散列表起始指针
    while (p)
    {
        std::cout << p->key << " ";
        if (p->key == key) //查找到数据
            return true;
        else
            p = p->next; //指向下一个结点
    }
    return false;
}
