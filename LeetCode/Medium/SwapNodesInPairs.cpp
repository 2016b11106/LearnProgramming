/**
 * 24. Swap Nodes in Pairs (赞数1099)
 * author 叶晨韬
 * date 2019/5/20
 **/
#include "../Leetcode.h"

/*给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 
示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.
*/
ListNode* swapPairs(ListNode* head) {
    ListNode dummyHead(-1), *pre = &dummyHead, *cur = head;
    pre->next = head;
    while(cur && cur->next)
    {
        ListNode *post = cur->next;
        pre->next = post;
        ListNode *tmp = post->next;
        post->next = cur;
        pre = cur;
        cur = tmp;
        pre->next = cur;
    }
    return dummyHead.next;
}
