/**
 * 2. Add Two Numbers (赞数5079)
 * author 叶晨韬
 * date 2019/5/13
 **/
#include "../Leetcode.h"

/*给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，
并且它们的每个节点只能存储 一位 数字。如果，我们将这两个数相加起来，则会返回
一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummyHead(-1), *pre = &dummyHead;
    int carry = 0;
    while(l1 || l2 || carry)
    {
        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        int sum = val1+val2+carry;
        carry = sum/10;
        ListNode *node = new ListNode(sum%10);
        pre->next = node;
        pre = pre->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return dummyHead.next;
}
