class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int sz = rows * cols;
        vector<vector<int>> ret; ret.reserve(sz);
        
        int step = 1, cnt = 0;
        int i = rStart, j = cStart, p = 0;
        while(ret.size() < sz) {
            // 每次走 1 1 2 2 3 3 ...
            for(int k=0; k<step; ++k) {
                if(i >= 0 && i < rows && j >= 0 && j < cols) {
                    ret.push_back({i, j});
                }
                i += dx[p], j += dy[p];
            }
            p = (p + 1) % 4;
            if(++cnt == 2) cnt = 0, ++step; //每走两步，加大步长
        }
        return ret;
    }
};
