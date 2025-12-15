// 方法一：额外矩阵
// time: O(mn), space: O(mn)

// 方法二：标记数组
// time: O(mn), space: O(m+n)

// 方法三：标记变量(双变量)
// time: O(mn), space: O(1)
class Solution {
    bool row, col; //标记第一行列是否置0
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<m; ++i) {
            if(matrix[i][0] == 0) {
                col = true; break;
            }
        }
        for(int j=0; j<n; ++j) {
            if(matrix[0][j] == 0) {
                row = true; break;
            }
        }

        // 用第一行与第一列作为标记数组
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // 用标记数组置0
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 用标记变量置0
        if(col) for(int i=0; i<m; ++i) matrix[i][0] = 0;
        if(row) for(int j=0; j<n; ++j) matrix[0][j] = 0;
    }
};

// 方法四：标记变量(单变量)
// time: O(mn), space: O(1)
class Solution {
    bool col; //标记第一列是否置0
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<m; ++i) {
            if(matrix[i][0] == 0) {
                col = true; break;
            }
        }
        for(int j=0; j<n; ++j) {
            if(matrix[0][j] == 0) {
                matrix[0][0] = 0; break; //[0][0]标记第一行是否置0
            }
        }

        // 用第一行与第一列作为标记数组
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // 用标记数组置0
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 用标记变量置0
        if(matrix[0][0] == 0) for(int j=0; j<n; ++j) matrix[0][j] = 0;
        if(col) for(int i=0; i<m; ++i) matrix[i][0] = 0;
    }
};
