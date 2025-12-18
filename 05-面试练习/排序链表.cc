// 方法一：归并排序（自顶向下，递归）
// time: O(nlogn), space: O(logn)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        auto newhead = partition(head);

        head = sortList(head);
        newhead = sortList(newhead);

        return merge(head, newhead);
    }

    ListNode* partition(ListNode* head) {
        auto slow = head, fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return fast;
    }

    ListNode* merge(ListNode* p1, ListNode* p2) {
        auto guard = new ListNode, cur = guard;
        while(p1 && p2) {
            if(p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }

        if(p1) cur->next = p1;
        if(p2) cur->next = p2;
        
        return guard->next;
    }
};


// 方法二：归并排序（自底向上，迭代）
// time: O(nlogn), space: O(1)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        int len = getLen(head);

        auto guard = new ListNode; guard->next = head;
        for(int step=1; step<len; step*=2) { //步长
            auto prev = guard, cur = guard->next;
            while(cur) {
                auto l = cur, r = cut(l, step);
                cur = cut(r, step);
                prev->next = merge(l, r);
                while(prev->next) prev = prev->next;
            }
        }
        return guard->next;
    }

    int getLen(ListNode* head) {
        auto cur = head; int len = 0;
        while(cur) cur = cur->next, ++len;
        return len;
    }

    // 切割链表前n个节点，返回第n+1个节点
    ListNode* cut(ListNode* head, int n) {
        auto cur = head;
        for(int i=0; i<n-1 && cur; ++i) {
            cur = cur->next;
        }
        if(!cur) return nullptr;
        auto next = cur->next;
        cur->next = nullptr;
        return next;
    }

    ListNode* merge(ListNode* p1, ListNode* p2) {
        auto guard = new ListNode, cur = guard;
        while(p1 && p2) {
            if(p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        if(p1) cur->next = p1;
        if(p2) cur->next = p2;
        return guard->next;
    }
};
