// 方法：堆
// time: O(nlogn), space: O(n)
class Solution {
    priority_queue<int> hp;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int x: stones) hp.push(x);
        while(hp.size() > 1) {
            int x = hp.top(); hp.pop();
            int y = hp.top(); hp.pop();
            if(x != y) hp.push(abs(x - y));
        }
        return hp.empty() ? 0 : hp.top();
    }
};
