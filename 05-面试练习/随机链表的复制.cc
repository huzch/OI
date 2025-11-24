/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// 方法一：交错新旧节点
// time: O(n) space: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 原节点后插入拷贝节点
        auto cur = head;
        while(cur) {
            auto copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        // 拷贝随机指针关系
        cur = head;
        while(cur) {
            auto copy = cur->next;
            copy->random = cur->random ? cur->random->next : nullptr;
            cur = copy->next;
        }

        // 分离拷贝节点
        auto guard = new Node(0), copytail = guard;
        cur = head;
        while(cur) {
            auto copy = cur->next;
            copytail->next = copy;
            copytail = copy;
            // 恢复原链表
            cur->next = copy->next;
            cur = cur->next;
        }

        return guard->next;
    }
};

// 方法二：回溯+哈希表
// time: O(n) space: O(n)
class Solution {
    unordered_map<Node*, Node*> hash; //<原链表,新链表>
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        if(!hash.count(head)) {
            hash[head] = new Node(head->val);
            hash[head]->next = copyRandomList(head->next);
            hash[head]->random = copyRandomList(head->random);
        }
        return hash[head];
    }
};
