// 方法一：暴力
// time: O(mn), space: O(1)

// 方法二：二分(一次)
// time: O(logmn), space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(matrix[mid / n][mid % n] >= target) r = mid;
            else l = mid + 1;
        }
        return matrix[l / n][l % n] == target;
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
