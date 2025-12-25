// 方法：单调栈（一次遍历优化）
// time: O(n), space: O(n)
class Solution {
    stack<int> st; //单调递增栈
public:
    int largestRectangleArea(vector<int>& heights) {
        st.push(-1); //哨兵, 处理仅有一个数在栈中的情况
        heights.push_back(-1); //处理栈中残留数据, 避免最后再循环处理
        int ret = 0, n = heights.size();
        for(int r = 0; r < n; ++r) { //优化: 一次遍历
            int h = heights[r];
            while(st.size() > 1 && heights[st.top()] >= h) {
                int i = st.top(); st.pop(); //矩形的高的下标
                int l = st.top(); //heights[l] < heights[i] >= heights[r]
                ret = max(ret, heights[i] * (r - l - 1));
            }
            st.push(r);
        }
        return ret;
    }
};

// 感想：对比这题和接雨水，同样单调栈做法，本题需要考虑额外边界(加哨兵)，而接雨水遇到无左边界则直接不统计
