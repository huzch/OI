// 方法一：list模拟，超时
class Solution {
public:
    int iceBreakingGame(int num, int target) {
        list<int> nums;
        for(int i=0; i<num; ++i) nums.emplace_back(i);

        auto it = nums.begin();
        while(nums.size() > 1) {
            for(int i=1; i<target; ++i) {
                ++it;
                if(it == nums.end()) it = nums.begin();
            }
            it = nums.erase(it);
            if(it == nums.end()) it = nums.begin();
        }
        return *it;
    }
};

// 方法二：数学推导公式
class Solution {
public:
    int iceBreakingGame(int num, int target) {
        // 假设num=5，target=3
        // 0 1 [2] 3 4 0 1 2 3 4    (0 + 3) % 5 = 3
        // 3 4 [0] 1 3 4 0 1    (1 + 3) % 4 = 0
        // 1 3 [4] 1 3 4    (1 + 3) % 3 = 1
        // 1 3 [1] 3    (0 + 3) % 2 = 1
        // 3
        // 精髓在于画图，并且往后复制一段数组
        // 然后根据图的规律，倒推答案的初始下标
        int ret = 0; //答案最终下标必定为0，因为只剩一个数
        for(int i=2; i<=num; ++i) {
            ret = (ret + target) % i;
        }
        return ret;
    }
};
