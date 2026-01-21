// 方法：前缀和+哈希表
// time: O(n), space: O(n)
class Solution {
    using LL = long long;
    unordered_map<LL, int> cnt; // <sum, cnt>
    int ret;
public:
    int pathSum(TreeNode* root, int targetSum) {
        cnt[0] = 1; // 处理sum == targetSum
        auto dfs = [&](this auto&& dfs, TreeNode* node, LL sum) {
            if(!node) return;
            sum += node->val;
            if(cnt.count(sum - targetSum)) ret += cnt[sum - targetSum];
            ++cnt[sum];
            dfs(node->left, sum);
            dfs(node->right, sum);
            --cnt[sum]; // 向上回退时，前缀和也要回退
        };
        dfs(root, 0);
        return ret;
    }
};
