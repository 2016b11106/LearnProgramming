/**
 * 23. Merge k Sorted Lists (赞数2413)
 * author 叶晨韬
 * date 2019/5/19
 **/
#include "../Leetcode.h"

/*合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例:
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
*/
struct cmp
{
    bool operator()(ListNode *n1, ListNode *n2){
        return n1->val > n2->val;
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode dummyHead(-1), *pre = &dummyHead;
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    for(int i = 0;i < lists.size();i++){
        if(lists[i])
            pq.push(lists[i]);
    }
    while(!pq.empty())
    {
        ListNode *node = pq.top();
        pre->next = node;
        pre = pre->next;
        pq.pop();
        if(node->next)
            pq.push(node->next);
    }
    return dummyHead.next;
}
