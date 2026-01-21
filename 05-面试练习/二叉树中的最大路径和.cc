// 方法：动态规划
// time: O(n), space: O(n)
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        auto dfs = [&](this auto&& dfs, TreeNode* node) {
            if(!node) return 0;
            // 后序遍历，才能实现DP，避免重复计算
            int lval = dfs(node->left);
            int rval = dfs(node->right);
            ret = max(ret, lval + rval + node->val);
            return max(0, max(lval, rval) + node->val);
        };
        dfs(root);
        return ret;
    }
};
