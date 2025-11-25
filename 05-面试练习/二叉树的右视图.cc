/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 方法一：bfs（层序遍历）
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        // 层序遍历，每层取最后一个
        vector<int> ret;
        queue<TreeNode*> q; q.emplace(root);
        while(!q.empty()) {
            int sz = q.size(), cur = 0;
            while(sz--) {
                auto node = q.front(); q.pop();
                cur = node->val;
                if(node->left) q.emplace(node->left);
                if(node->right) q.emplace(node->right);
            }
            ret.emplace_back(cur);
        }
        return ret;
    }
};

// 方法二：dfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        auto dfs = [&](this auto&& dfs, TreeNode* root, int depth) {
            if(root == nullptr) return;
            if(depth == ret.size()) {
                ret.emplace_back(root->val);
            }
            //先遍历右子树，保证达到新的高度时，先添加右节点
            dfs(root->right, depth + 1);
            dfs(root->left, depth + 1);
        };
        dfs(root, 0);
        return ret;
    }
};
