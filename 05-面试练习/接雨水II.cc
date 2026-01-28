// 方法：维护最外层双指针，向内收缩（接雨水的拓展）
// time: O(mnlogmn), space: O(mn)
class Solution {
    using T = tuple<int, int, int>;
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<T, vector<T>, greater<>> hp;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    hp.push({heightMap[i][j], i, j});
                    heightMap[i][j] = -1; // 标记已访问
                }
            }
        }

        int ret = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while(!hp.empty()) {
            auto [h, i, j] = hp.top(); hp.pop();
            for(int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if(x >= 0 && x < m && y >= 0 && y < n && heightMap[x][y] >= 0) {
                    ret += max(h - heightMap[x][y], 0);
                    hp.push({max(h, heightMap[x][y]), x, y});
                    heightMap[x][y] = -1;
                }
            }
        }
        return ret;
    }
};
