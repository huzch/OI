// 方法一：堆模拟
// time: O(mnlogn), space: O(mn)
class Solution {
    vector<priority_queue<int>> v;
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        v.reserve(m);
        for(auto& row: grid) {
            priority_queue<int> hp;
            for(int x: row) hp.push(x);
            v.push_back(hp);
        }

        int ret = 0;
        for(int i=0; i<n; ++i) {
            int maxval = 0;
            for(auto& hp: v) {
                int x = hp.top(); hp.pop();
                maxval = max(maxval, x);
            }
            ret += maxval;
        }
        return ret;
    }
};

// 方法二：排序
// time: O(mnlogn), space: O(1)
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(auto& row: grid) {
            ranges::sort(row);
        }

        int ret = 0;
        int m = grid.size(), n = grid[0].size();
        for(int j=0; j<n; ++j) {
            int maxval = 0; //求每列最大值
            for(int i=0; i<m; ++i) {
                maxval = max(maxval, grid[i][j]);
            }
            ret += maxval;
        }
        return ret;
    }
};
