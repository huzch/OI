// 方法一：暴力
// time: O(mn), space: O(1)

// 方法二：二分(逐行/逐列)
// time: O(mlogn/nlogm), space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<m; ++i) {
            int l = 0, r = n - 1;
            while(l < r) {
                int mid = (l + r) >> 1;
                if(matrix[i][mid] >= target) r = mid;
                else l = mid + 1;
            }
            if(matrix[i][l] == target) return true;
        }
        return false;
    }
};

// 方法三：抽象BST
// time: O(m+n), space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0; //左下角与右上角均可
        while(i >= 0 && j < n) {
            if(target < matrix[i][j]) --i;
            else if(target > matrix[i][j]) ++j;
            else return true;
        }
        return false;
    }
};
