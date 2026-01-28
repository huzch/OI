// 方法：二分
// time: O(log(min(m,n))), space: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 短数组上二分，防越界且效率高
        if(nums1.size() > nums2.size()) swap(nums1, nums2);

        int m = nums1.size(), n = nums2.size();
        int totalL = (m + n + 1) >> 1; // +1保证左边>=右边
        int l = 0, r = m;
        while(l < r) {
            int i = (l + r) >> 1, j = totalL - i;
            if(nums1[i] >= nums2[j - 1]) r = i;
            else l = i + 1;
        }

        int i = l, j = totalL - i;
        int n1LMax = i == 0 ? INT_MIN : nums1[i - 1];
        int n2LMax = j == 0 ? INT_MIN : nums2[j - 1];
        int n1RMin = i == m ? INT_MAX : nums1[i];
        int n2RMin = j == n ? INT_MAX : nums2[j];
        int LMax = max(n1LMax, n2LMax);
        int RMin = min(n1RMin, n2RMin);

        if((m + n) & 1) return LMax;
        else return (LMax + RMin) / 2.0;
    }
};
