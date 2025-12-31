class Solution {
public:
    vector<vector<int>> rotateMatrix(vector<vector<int>>& mat, int n) {
        // [i][j] -> [j][n-i-1]
        // 行交换
        for(int i = 0; i < n / 2; ++i) {
            swap(mat[i], mat[n - i - 1]);
        }
        // 对角交换
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        return mat;
    }
};
