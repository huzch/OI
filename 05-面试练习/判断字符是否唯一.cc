// 方法：位运算（要求不使用额外数据结构）
// time: O(n), space: O(1)
class Solution {
    int ht; //位图哈希
public:
    bool isUnique(string astr) {
        if(astr.size() > 26) return false;
        for(char ch: astr) {
            if((ht >> ch - 'a') & 1) return false;
            ht |= (1 << ch - 'a');
        }
        return true;
    }
};
