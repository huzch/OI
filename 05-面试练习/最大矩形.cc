// 方法：单调栈
// time: O(mn), space: O(n)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ret = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n + 1); //最后一个0用来大火收汁
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') ++heights[j];
                else heights[j] = 0;
            }
            ret = max(ret, find(heights));
        }
        return ret;
    }

    // 柱状图中最大的矩形
    int find(vector<int>& heights) {
        stack<int> st; st.push(-1); //哨兵
        int ret = 0, n = heights.size();
        for(int r = 0; r < n; ++r) {
            int h = heights[r];
            while(st.size() > 1 && heights[st.top()] >= h) {
                int i = st.top(); st.pop(); //高
                int l = st.top();
                ret = max(ret, heights[i] * (r - l - 1));
            }
            st.push(r);
        }
        return ret;
    }
};
