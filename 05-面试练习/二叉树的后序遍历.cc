// 方法一：单栈，非递归
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;

        TreeNode* vis = nullptr;
        auto cur = root;
        while(cur || !st.empty()) {
            while(cur) {
                st.emplace(cur);
                cur = cur->left;
            }

            auto node = st.top();
            if(node->right && node->right != vis) {
                cur = node->right;
            } else { //最近访问的节点为本节点的右孩子，则表示已访问完右子树
                ret.emplace_back(node->val);
                vis = node;
                st.pop();
            }
        }
        return ret;
    }
};
