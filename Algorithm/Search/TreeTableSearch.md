# 树表查找
## 二叉树查找算法
## 基本思想：  
**二叉排序树**（简称BST）又称二叉查找（搜索）树，其定义为：二叉排序树或者是空树，或者是满足如下性质的二叉树：  
（1）若它的左子树非空，则左子树上所有记录的值均小于根记录的值；  
（2）若它的右子树非空,则右子树上所有记录的值均大于根记录的值；  
（3）左、右子树本身又各是一棵二叉排序树。  
在讨论二叉排序树上的运算之前,定义其节点的类型如下：  
```c
  typedef struct node          //记录类型   
  {	
    KeyType key;            	//关键字项    	
    InfoType data;          	//其他数据域    	
    struct node *lchild,*rchild;//左右孩子指针   
  } BSTNode;
```
## 二叉排序树上的查找
因为二叉排序树可看做是一个有序表，所以在二叉排序树上进行查找，和二分查找类似，也是一个逐步缩小查找范围的过程。  
递归查找算法SearchBST()如下（在二叉排序树bt上查找关键字为k的记录,成功时返回该节点指针，否则返回NULL）：  
```c
BSTNode *SearchBST(BSTNode *bt,KeyType k) {  
    if (bt==NULL || bt->key==k)      	//递归终结条件       
        return bt;    
    if (k<bt->key)    　 
        return SearchBST(bt->lchild,k); //在左子树中递归查找    
    else    　 
        return SearchBST(bt->rchild,k); //在右子树中递归查找 
}
```   
也可以采用如下非递归算法：  
```c
BSTNode *SearchBST1(BSTNode *bt,KeyType k){  
    while (bt!=NULL)   
    {      
        if (k==bt->key)          
            return bt;      
        else if (k<bt->key)          
            bt=bt->lchild;  //在左子树中递归查找     
        else          
            bt=bt->rchild;  //在左子树中递归查找   
    }   
    return NULL;            //没有找到返回NULL      
}
```
**复杂度分析：它和二分查找一样，插入和查找的时间复杂度均为O(logn)，但是在最坏的情况下仍然会有O(n)的时间复杂度。**
下图为二叉树查找和顺序查找以及二分查找性能的对比图：  
<!-- ![image](https://github.com/2016b11106/LearnProgramming/blob/master/photo/search-1.png?raw=true) -->
![image](/photo/search-1.png)