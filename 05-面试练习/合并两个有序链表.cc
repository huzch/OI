// 方法一：递归
// time: O(m+n), space: O(m+n)

// 方法二：迭代
// time: O(m+n), space: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto guard = new ListNode, tail = guard;
        auto p1 = list1, p2 = list2;
        while(p1 && p2) {
            if(p1->val < p2->val) {
                tail->next = p1;
                p1 = p1->next;
            } else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }

        if(p1) tail->next = p1;
        if(p2) tail->next = p2;
        return guard->next;
    }
};
