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
    void reorderList(ListNode* head) {
        //只有1或2个节点，不处理
        if(!head->next || !head->next->next) return;

        //从中间分割链表,分出h1与h2
        ListNode* newhead = nullptr;
        partition(head, newhead);

        //逆序h2
        reverse(newhead);

        //合并h1与h2
        merge(head, newhead);
    }

    void partition(ListNode* h1, ListNode*& h2) {
        //快慢指针找中点
        auto slow = h1, fast = h1->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        h2 = slow->next;
        slow->next = nullptr; //切割链表
    }

    void reverse(ListNode*& h2) {
        ListNode* prev = nullptr;
        while(h2) {
            auto next = h2->next;
            h2->next = prev;
            prev = h2;
            h2 = next;
        }
        h2 = prev;
    }

    void merge(ListNode* h1, ListNode* h2) {
        auto guard = new ListNode, cur = guard;
        bool flag = true;
        while(h1 && h2) {
            if(flag) {
                cur->next = h1;
                h1 = h1->next;
            } else {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
            flag = !flag;
        }

        if(h1) cur->next = h1;
        if(h2) cur->next = h2;
        delete guard;
    }
};
