// 方法：模拟（数学规律）
// time: O(log10(n)), space: O(log10(n))
class Solution {
    using LL = long long;
public:
    int findNthDigit(int n) {
        // len：位数，begin：位数区间首部，cnt：位数区间长度
        LL len = 1, begin = 1, cnt = 9;
        while(n > len * cnt) {
            n -= len * cnt;
            ++len, begin *= 10, cnt *= 10;
        }

        LL num = begin + (n - 1) / len; // 找到对应数字
        LL i = (n - 1) % len; // 找到数字对应位
        return to_string(num)[i] - '0';
    }
};
