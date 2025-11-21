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
    int posti;
    unordered_map<int, int> hash; //<value,index>
public:
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int inbegin, int inend) {
        if(inbegin > inend) return nullptr;

        // 后序找到根的值
        int rootval = postorder[posti--];
        // 中序找到根的下标
        int rooti = hash[rootval];
        // 根据下标分割区间递归(根右左)
        auto root = new TreeNode(rootval);
        root->right = dfs(inorder, postorder, rooti + 1, inend);
        root->left = dfs(inorder, postorder, inbegin, rooti - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        posti = n - 1;
        for(int i=0; i<n; ++i) hash[inorder[i]] = i;
        return dfs(inorder, postorder, 0, n - 1);
    }
};
