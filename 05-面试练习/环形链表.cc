// 方法一：哈希表
// time: O(n), space: O(n)

// 方法二：快慢指针
// time: O(n), space: O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        auto slow = head, fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
