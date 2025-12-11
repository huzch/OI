// 方法一：动态规划
// time: O(n^2), space: O(n^2)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n));
        // f[i][j]: [i,j]区域最长回文子序列的长度
        // f[i][j] = s[i] == s[j] ? f[i+1][j-1] + 2 : max(f[i][j-1], f[i+1][j])
        // 所以求i要先求i+1,求j要先求j-1
        for(int i=n-1; i>=0; --i) {
            f[i][i] = 1; //先初始化单个字母的情况，使得j从i+1讨论
            for(int j=i+1; j<n; ++j) {
                f[i][j] = s[i] == s[j] ? f[i+1][j-1] + 2 : max(f[i][j-1], f[i+1][j]);
            }
        }
        return f[0][n - 1];
    }
};
