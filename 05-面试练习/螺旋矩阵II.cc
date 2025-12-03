// 写法一：压缩边界
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int x = 0, y = 0, k = 1;
        int up = 0, down = n - 1, left = 0, right = n - 1;
        while(left <= right) {
            while(x == up && y != right) {
                ret[x][y++] = k++;
            }
            if(++up > down) break;
            while(x != down && y == right) {
                ret[x++][y] = k++;
            }
            if(--right < left) break;
            while(x == down && y != left) {
                ret[x][y--] = k++;
            }
            if(--down < up) break;
            while(x != up && y == left) {
                ret[x--][y] = k++;
            }
            if(++left > right) break;
        }
        ret[x][y] = k;
        return ret;
    }
};

// 写法二：标记已访问+方向向量
class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int sz = n * n;

        int i = 0, j = 0, p = 0;
        for(int k=1; k<=sz; ++k) {
            ret[i][j] = k;
            int x = i + dx[p], y = j + dy[p];
            if(x < 0 || x >= n || y < 0 || y >= n || ret[x][y]) {
                p = (p + 1) % 4;
            }
            i += dx[p], j += dy[p];
        }
        return ret;
    }
};
