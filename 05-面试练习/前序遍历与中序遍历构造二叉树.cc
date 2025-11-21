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
class Solution {
    int prei;
    unordered_map<int, int> hash;
public:
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int inbegin, int inend) {
        if(inbegin > inend) return nullptr;

        // 前序找到根的值
        int rootval = preorder[prei++];
        // 中序找到根的下标
        int rooti = hash[rootval];
        // 分割区间递归(根左右)
        auto root = new TreeNode(rootval);
        root->left = dfs(preorder, inorder, inbegin, rooti - 1);
        root->right = dfs(preorder, inorder, rooti + 1, inend);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0; i<n; ++i) hash[inorder[i]] = i;
        return dfs(preorder, inorder, 0, n - 1);
    }
};
