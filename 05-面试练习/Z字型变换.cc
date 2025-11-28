// 方法一：模拟（压缩空间版）
// time: O(n), space: O(n)
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> mat(numRows);
        int dx[] = {1, -1};
        int x = 0, k = 0;
        for(char ch: s) {
						//只存储有效字符，有效压缩矩阵空间，方向向量也节省一维，收集结果时也更快速
            mat[x].push_back(ch); 
            if(x == 0) k = 0;
            if(x == numRows - 1) k = 1;
            x += dx[k];
        }

        string ret;
        for(auto& str: mat) ret += str;
        return ret;
    }
};

// 方法二：数学
// time: O(n), space: O(1)
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size(), r = numRows;
        if(r == 1 || r >= n) return s;

        string ret;
        int t = 2 * r - 2; //周期
        for(int i=0; i<r; ++i) { //枚举行
            for(int j=0; i+j<n; j+=t) { //枚举周期
                ret += s[i + j];
                // 除首尾行，其余中间行每周期有两个字符
                if(i == 0 || i == r - 1) continue;
                if(t - i + j < n) ret += s[t - i + j];
            }
        }
        return ret;
    }
};
