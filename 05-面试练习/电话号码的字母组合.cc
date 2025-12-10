class Solution {
    unordered_map<char, string> hash = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                       {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                       {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ret;
    string path;

public:
    vector<string> letterCombinations(string digits) {
        dfs(digits, 0);
        return ret;
    }

    void dfs(string& digits, int pos) {
        if (path.size() == digits.size()) {
            ret.emplace_back(path);
            return;
        }

        auto& s = hash[digits[pos]];
        for (char ch: s) {
            path += ch;
            dfs(digits, pos + 1);
            path.pop_back();
        }
    }
};
