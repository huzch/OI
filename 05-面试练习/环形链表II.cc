// 方法一：哈希表
// time: O(n), space: O(n)

// 方法二：快慢指针
// time: O(n), space: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        auto slow = head, fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                auto cur = head;
                while(cur != slow) {
                    cur = cur->next;
                    slow = slow->next;
                }
                return cur;
            }
        }
        return nullptr;
    }
};
