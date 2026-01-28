// 方法：堆
class MedianFinder {
	  // left 与 right 相等，或比 right 多 1
    priority_queue<int> left; // 大堆
    priority_queue<int, vector<int>, greater<>> right; // 小堆
public:
    void addNum(int num) {
        if(left.size() == right.size()) {
            right.push(num);
            left.push(right.top());
            right.pop();
        } else {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        return left.top();
    }
};
