// 方法：dfs（回溯：枚举选哪个）
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ret;
        string path;
        vector<string> ht = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        auto dfs = [&](this auto&& dfs, int i) {
            if(i == n) {
                ret.push_back(path);
                return;
            }

            int j = digits[i] - '0';
            for(char ch: ht[j]) {
                path.push_back(ch);
                dfs(i + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return ret;
    }
};
