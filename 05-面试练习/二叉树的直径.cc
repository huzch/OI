// 二叉树最大深度变式
// 统计所有节点的直径中的最大值，而单个节点直径是左右子树最大高度之和
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ret = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) {
            if(!root) return 0;
            int lh = dfs(root->left);
            int rh = dfs(root->right);
            ret = max(ret, lh + rh);
            return max(lh, rh) + 1;
        };
        dfs(root);
        return ret;
    }
};
