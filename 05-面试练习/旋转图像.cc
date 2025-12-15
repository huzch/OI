// 方法：数学（多次翻转等于旋转）
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 顺时针旋转90度, [i][j]->[j][n-i-1]
        int m = matrix.size(), n = matrix[0].size();
        // 先转置, [i][j]->[j][i]
        for(int i=0; i<m; ++i) {
            for(int j=0; j<i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 再行翻转, [j][i]->[j][n-i-1]
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n/2; ++j) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};
