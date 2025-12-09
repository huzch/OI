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
// 方法一：记录链表长度
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        auto tail = head;
        while(tail) tail = tail->next, ++len;

        auto guard = new ListNode; guard->next = head;
        auto prev = guard, cur = head;
        for(int i=0; i<len-n; ++i) {
            prev = cur, cur = cur->next;
        }
        prev->next = cur->next;
        delete cur;
        return guard->next;
    }
};

// 方法二：前后指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto guard = new ListNode; guard->next = head;
        auto slow = guard, fast = head;
        while(n--) fast = fast->next;
        while(fast) slow = slow->next, fast = fast->next;
        auto del = slow->next;
        slow->next = del->next;
        delete del;
        return guard->next;
    }
};
