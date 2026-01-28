class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> ht;
        int n = inorder.size();
        for(int i = 0; i < n; ++i) {
            ht[inorder[i]] = i;
        }

        int prei = 0;
        auto dfs = [&](this auto&& dfs, int begin, int end) ->TreeNode* {
            if(begin > end) return nullptr;
						// 前序找到根的值
            int rootval = preorder[prei++];
						// 中序找到根的下标
            int rooti = ht[rootval];
						// 分割区间递归(根左右)
            auto root = new TreeNode(rootval);
            root->left = dfs(begin, rooti - 1);
            root->right = dfs(rooti + 1, end);
            return root;
        };
        return dfs(0, n - 1);
    }
};
