// 方法一：dfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return minDepth(root->right) + 1;
        if(!root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        int ret = INT_MAX;
        auto dfs = [&](this auto&& dfs, TreeNode* root, int cnt = 0) {
            if(!root || ++cnt >= ret) return; //最优性剪枝
            if(!root->left && !root->right) {
                ret = min(ret, cnt); return;
            }
            dfs(root->left, cnt);
            dfs(root->right, cnt);
        };
        dfs(root);
        return ret == INT_MAX ? 0 : ret;
    }
};

// 方法二：bfs（比dfs能更快剪枝找到结果）
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q; q.push(root);
        int ret = 0;
        while(!q.empty()) {
            ++ret;
            int sz = q.size();
            while(sz--) {
                auto node = q.front(); q.pop();
                if(!node->left && !node->right) return ret;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ret;
    }
};
