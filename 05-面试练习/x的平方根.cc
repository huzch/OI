// 左边界二分
// x的平方根若在[i, i + 1]之间，应向下取整，所以正好对应l=mid左边界
class Solution {
public:
    int mySqrt(int x) {
        long l = 0, r = x;
        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            if(mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
