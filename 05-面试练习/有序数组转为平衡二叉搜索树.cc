class Solution {
public:
    // 有序数组是二叉搜索树的中序遍历，要保持平衡则每次选取区间中点作为根
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto dfs = [&](this auto&& dfs, int begin, int end) ->TreeNode* {
            if(begin > end) return nullptr;
            int mid = (begin + end) >> 1;
            auto root = new TreeNode(nums[mid]);
            root->left = dfs(begin, mid - 1);
            root->right = dfs(mid + 1, end);
            return root;
        };
        return dfs(0, nums.size() - 1);
    }
};
