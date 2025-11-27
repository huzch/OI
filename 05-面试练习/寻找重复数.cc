class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // i->nums[i]: i视为当前节点，nums[i]视为下一节点
        // i∈[0,n], nums[i]∈[1,n]: 每个点出度均为1
        // 每个点出度均为1的有向图叫做内向基环森林，每个连通分量都恰好有一个环
        // 每个点的入度，就是在nums中的出现次数，入环口入度大于1，即重复数
        // 必须从节点0出发，否则可能会找不到入环口，因为节点0的入度为0，一定不在环上，环上节点入度至少为1
        // 仅考虑包含节点0的连通分量，含有一个环，用快慢指针法找到入环口
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        int cur = 0;
        while(slow != cur) {
            slow = nums[slow];
            cur = nums[cur];
        }
        return cur;
    }
};
