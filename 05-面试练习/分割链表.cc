/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto guard = new ListNode(0, head);
        auto prev = guard, cur = head;
        while(cur) {
            if(prev != guard && cur->val < x) {
                // 抽离
                prev->next = cur->next;
                // 头插
                cur->next = guard->next;
                guard->next = cur;
                // 复位
                cur = prev->next;
            } else {
                prev = cur;
                cur = prev->next;
            }
        }
        return guard->next;
    }
};
