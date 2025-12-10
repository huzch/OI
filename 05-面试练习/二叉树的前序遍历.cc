// 方法一：单栈，非递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;

        auto cur = root;
        while(cur || !st.empty()) {
            while(cur) {
                ret.emplace_back(cur->val); //入栈前访问
                st.emplace(cur);
                cur = cur->left;
            }

            auto node = st.top();
            cur = node->right;
            st.pop();
        }
        return ret;
    }
};
