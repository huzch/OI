class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;

        auto guard = new ListNode; guard->next = head;
        auto prev = guard, cur = head;
        while(cur) {
            if(cur->val == val) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return guard->next;
    }
};
