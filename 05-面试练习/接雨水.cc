// 方法一：左右扫描线
// time: O(n), space: O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        left[0] = height[0];
        for(int i=1; i<n; ++i) {
            left[i] = max(left[i - 1], height[i]);
        }

        vector<int> right(n);
        right[n - 1] = height[n - 1];
        for(int i=n-2; i>=0; --i) {
            right[i] = max(right[i + 1], height[i]);
        }

        int ret = 0;
        for(int i=0; i<n; ++i) {
            ret += min(left[i], right[i]) - height[i];
        }
        return ret;
    }
};

// 方法二：优化，左右双指针
// time: O(n), space: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ret = 0, lmax = 0, rmax = 0;
        while(l < r) { //相遇时在最高柱，不用计算
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            // 谁小谁移动，是为了l与r从两边走到最高柱
            ret += lmax < rmax ? lmax - height[l++] : rmax - height[r--];
        }
        return ret;
    }
};

// 方法三：单调栈
// time: O(n), space: O(n)
// 此解法优势在于可以只从左向右遍历，若输入为流，则十分有用
class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0, n = height.size();
        // 维护单调递减栈，若遇到比栈顶高的柱子，则形成了低洼，可以接水
        stack<int> st;
        for(int i=0; i<n; ++i) {
            while(!st.empty() && height[st.top()] <= height[i]) {
                int down = st.top(); st.pop();
                if(st.empty()) break; //无左边界
                int left = st.top();
                int dh = min(height[left], height[i]) - height[down];
                ret += (i - left - 1) * dh;
            }
            st.emplace(i); //只有>才加入，=不加入，减少空间占用
        }
        return ret;
    }
};
