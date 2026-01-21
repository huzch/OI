// 方法：利用满二叉树性质
// time: O(logn*logn), space: O(n)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        auto l = root, r = root;
        int lh = 0, rh = 0;
        while(l) l = l->left, ++lh;
        while(r) r = r->right, ++rh;

        // 若相等，则为满二叉树，用树高计算节点个数
        if(lh == rh) return (1 << lh) - 1;
        // 不相等，则递归左右子树，总有一方为满二叉树
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
