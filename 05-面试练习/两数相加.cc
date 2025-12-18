// 方法：模拟
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto guard = new ListNode, cur = guard;
        auto p1 = l1, p2 = l2;
        int carry = 0;
        while(p1 || p2) {
            carry += (p1 ? p1->val : 0) + (p2 ? p2->val : 0);
            cur->next = new ListNode(carry % 10);
            carry /= 10;
            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
            cur = cur->next;
        }

        if(carry) cur->next = new ListNode(1);

        return guard->next;
    }
};
