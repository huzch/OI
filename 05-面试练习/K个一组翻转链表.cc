class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;

        auto guard = new ListNode; guard->next = head;
        auto prev = guard, cur = guard;
        while(cur) {
            for(int i=0; i<k; ++i) {
                cur = cur->next;
                if(!cur) return guard->next;
            }

            auto next = prev->next;
            reverse(prev->next, cur->next);
            prev = cur = next;
        }
        return guard->next;
    }

    void reverse(ListNode*& head, ListNode* tail) {
        auto prev = tail, cur = head;
        while(cur != tail) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur, cur = next;
        }
        head = prev;
    }
};
