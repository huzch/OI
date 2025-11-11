// 方法一：调用reverse函数
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

// 方法二：手动实现
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            swap(s[left++], s[right--]);
        }
    }
};
