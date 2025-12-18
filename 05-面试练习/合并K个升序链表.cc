// 方法一：堆
// time: O(Lnlogn), space: O(n), L为链表平均长度
class Solution {
    struct cmp {
        bool operator()(ListNode* p1, ListNode* p2) {
            return p1->val > p2->val;
        }
    };
    priority_queue<ListNode*, vector<ListNode*>, cmp> hp;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto p: lists) if(p) hp.push(p);
        auto guard = new ListNode, cur = guard;
        while(!hp.empty()) {
            auto p = hp.top(); hp.pop();
            cur->next = p; cur = cur->next;
            if(p->next) hp.push(p->next);
        }
        return guard->next;
    }
};

// 方法二：分治（自顶向下，递归）
// time: O(Lnlogn), space: O(logn), L为链表平均长度
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    ListNode* mergeKLists(vector<ListNode*>& a, int begin, int end) {
        if(begin == end) return a[begin];

        int mid = (begin + end) >> 1;
        auto p1 = mergeKLists(a, begin, mid);
        auto p2 = mergeKLists(a, mid + 1, end);

        return merge(p1, p2);
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

// 方法三：分治（自底向上，迭代）
// time: O(Lnlogn), space: O(1), L为链表平均长度
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        for(int step=1; step<n; step*=2) {
            for(int i=0; i<n-step; i+=step*2) {
                lists[i] = merge(lists[i], lists[i + step]);
            }
        }
        return lists[0];
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
