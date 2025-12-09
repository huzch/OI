class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        dfs(A, C, B, A.size());
    }

    void dfs(vector<int>& src, vector<int>& dst, vector<int>& tmp, int n) {
        if(n == 0) return;

        dfs(src, tmp, dst, n - 1);
        dst.emplace_back(src.back());
        src.pop_back();
        dfs(tmp, dst, src, n - 1);
    }
};
