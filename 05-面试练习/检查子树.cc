// 方法一：高度剪枝
class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        auto height = [&](this auto&& height, TreeNode* root) {
            if(!root) return 0;
            return max(height(root->left), height(root->right)) + 1; 
        };
        auto same = [&](this auto&& same, TreeNode* s, TreeNode* t) {
            if(!s && !t) return true;
            if(!s || !t) return false;
            return s->val == t->val && same(s->left, t->left) && same(s->right, t->right);
        };

        bool ret = false;
        int th = height(t2);
        auto dfs = [&](this auto&& dfs, TreeNode* root) {
            if(!root) return 0;
            int h = max(dfs(root->left), dfs(root->right)) + 1;
            if(h == th && same(root, t2)) ret = true;
            return h;
        };
        dfs(t1);
        return ret;
    }
};

// 方法二：哈希剪枝
class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        uint64_t l = 179, r = 131; // 质数
        auto hash = [&](this auto&& hash, TreeNode* root) ->uint64_t {
            if(!root) return 3;
            return root->val + hash(root->left) * l + hash(root->right) * r; 
        };
        auto same = [&](this auto&& same, TreeNode* s, TreeNode* t) {
            if(!s && !t) return true;
            if(!s || !t) return false;
            return s->val == t->val && same(s->left, t->left) && same(s->right, t->right);
        };

        bool ret = false;
        uint64_t th = hash(t2);
        auto dfs = [&](this auto&& dfs, TreeNode* root) ->uint64_t {
            if(!root) return 3;
            uint64_t h = root->val + dfs(root->left) * l + dfs(root->right) * r;
            if(h == th && same(root, t2)) ret = true;
            return h;
        };
        dfs(t1);
        return ret;
    }
};
