// 方法：dfs
// time: O(n), space: O(n)
class Solution {
public: // 最外层调用返回最近公共祖先，内层调用有可能返回p、q或空
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);
        if(l && r) return root;
        return l ? l : r; // 哪边有返回哪边，都没有返回空
    }
};
