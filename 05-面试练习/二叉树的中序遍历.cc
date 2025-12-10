// 方法一：单栈，非递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;

        auto cur = root;
        while(cur || !st.empty()) {
            while(cur) {
                st.emplace(cur);
                cur = cur->left;
            }

            auto node = st.top();
            ret.emplace_back(node->val); //出栈后访问
            cur = node->right;
            st.pop();
        }
        return ret;
    }
};
