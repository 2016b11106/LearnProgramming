/**
 * 21. Merge Two Sorted Lists (赞数2183)
 * author 叶晨韬
 * date 2019/5/18
 **/
#include "../Leetcode.h"

/*将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummyHead(-1), *pre = &dummyHead;
    while(l1 && l2)
    {
        if(l1->val >= l2->val){
            pre->next = l2;
            l2 = l2->next;
        }else{
            pre->next = l1;
            l1 = l1->next;
        }
        pre = pre->next;
    }
    pre->next = l1 ? l1 : l2;
    return dummyHead.next;       
}

ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    if(l1->val >= l2->val){
        l2->next = mergeTwoLists2(l1, l2->next);
        return l2;
    }else{
        l1->next = mergeTwoLists2(l1->next, l2);
        return l1;
    }
}
