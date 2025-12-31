// 方法：模拟
// time: O(n^2), space: O(n)
class Solution {
    static constexpr int N = 1e4 + 10;
    using LL = long long;
    LL a[N], b[N], c[2 * N];
public:
    string solve(string s, string t) {
        int m = s.size(), n = t.size();
        for(int i = 0; i < m; ++i) a[i] = s[m - i - 1] - '0';
        for(int i = 0; i < n; ++i) b[i] = t[n - i - 1] - '0';
        
        // 不进位相乘
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                c[i + j] += a[i] * b[j];
            }
        }
        // 进位相加
        for(int i = 0; i < m + n; ++i) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }

        string ret; ret.reserve(m + n);
        for(int i = 0; i < m + n; ++i) ret += c[i] + '0';
        // 去除前导零
        while(ret.size() > 1 && ret.back() == '0') ret.pop_back();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
