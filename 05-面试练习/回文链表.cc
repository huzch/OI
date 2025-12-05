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
    bool isPalindrome(ListNode* head) {
        ListNode* newhead = nullptr;
        partition(head, newhead);
        reverse(newhead);
        while(newhead) {
            if(head->val != newhead->val) {
                return false;
            }
            head = head->next;
            newhead = newhead->next;
        }
        return true;
    }

    void partition(ListNode* head, ListNode*& newhead) {
        auto slow = head, fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        newhead = slow->next;
        slow->next = nullptr;
    }

    void reverse(ListNode*& head) {
        ListNode* prev = nullptr;
        while(head) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
    }
};
