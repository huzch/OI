// 方法：dfs（回溯+剪枝优化）
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        unordered_map<char, int> cnt, wcnt;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                ++cnt[board[i][j]];
            }
        }
        for(char ch: word) { // 可行性剪枝
            if(++wcnt[ch] > cnt[ch]) return false; // 优化一
        }
        if(cnt[word.back()] < cnt[word[0]]) { // 顺序剪枝
            ranges::reverse(word); // 优化二
        }


        auto dfs = [&](this auto&& dfs, int i, int j, int p) {
            if(p == word.size()) return true;
            
            vis[i][j] = true;
            for(int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if(x >= 0 && x < m && y >= 0 && y < n 
                && !vis[x][y] && board[x][y] == word[p]) {
                    if(dfs(x, y, p + 1)) return true;
                }
            }
            vis[i][j] = false;
            return false;
        };
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 1)) return true;
                }
            }
        }
        return false;
    }
};
