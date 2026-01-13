class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, TreeNode* root) {
            if(!root) return;
            swap(root->left, root->right);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        return root;
    }
};
