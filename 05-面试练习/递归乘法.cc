class Solution {
public:
    int multiply(int A, int B) { //目前只能处理正整数
        // 倍增思想: A + 2A + 4A + ...(B对应位为1时累加)
        return B ? (B & 1 ? A : 0) + multiply(A << 1, B >> 1) : 0;
    }
};
