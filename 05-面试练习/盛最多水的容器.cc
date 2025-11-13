class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int left = 0, right = height.size() - 1;
        while(left < right) {
            int area = min(height[left], height[right]) * (right - left);
            ret = max(ret, area);
            //移动短板，可能获得更大收益；移动长板，必定亏损
            if(height[left] < height[right]) ++left;
            else --right;
        }
        return ret;
    }
};
