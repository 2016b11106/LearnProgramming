/**
 * 19. Remove Nth Node From End of List (赞数1755)
 * author 叶晨韬
 * date 2019/5/17
 **/
#include "../Leetcode.h"

/*给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：
给定的 n 保证是有效的。
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummyHead(-1), *p1 = &dummyHead, *p2 = head;
    p1->next = head;
    while(n)
    {
        p2 = p2->next;
        n--;
    }
    while(p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    ListNode *node = p1->next;
    p1->next = node->next;
    return dummyHead.next;
}
