// 写法一：压缩边界
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ret; ret.reserve(m * n);

        int x = 0, y = 0;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while(left <= right) {
            while(x == up && y != right) {
                ret.emplace_back(matrix[x][y++]);
            }
            if(++up > down) break;
            while(x != down && y == right) {
                ret.emplace_back(matrix[x++][y]);
            }
            if(--right < left) break;
            while(x == down && y != left) {
                ret.emplace_back(matrix[x][y--]);
            }
            if(--down < up) break;
            while(x != up && y == left) {
                ret.emplace_back(matrix[x--][y]);
            }
            if(++left > right) break;
        }
        ret.emplace_back(matrix[x][y]);
        return ret;
    }
};

// 写法二：标记已访问+方向向量
class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int sz = m * n;
        vector<int> ret(sz);

        int i = 0, j = 0, p = 0;
        for(int k=0; k<sz; ++k) {
            ret[k] = matrix[i][j];
            matrix[i][j] = INT_MAX; //标记已访问
            int x = i + dx[p], y = j + dy[p];
            if(x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == INT_MAX) {
                p = (p + 1) % 4;
            }
            i += dx[p], j += dy[p];
        }
        return ret;
    }
};
