// 头插法
// time: O(n), space: O(n)
class Solution {
    TreeNode* prev;
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        // 反前序遍历：右 左 根
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = prev;
        prev = root;
    }
};
