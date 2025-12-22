// 方法一：二分
// time: O(logn), space: O(n)
class RecentCounter {
    vector<int> a;
public:
    int ping(int t) {
        a.push_back(t);
        int l = 0, r = a.size() - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(a[mid] >= t - 3000) r = mid;
            else l = mid + 1;
        }
        return a.size() - l;
    }
};

class RecentCounter {
    vector<int> a;
public:
    int ping(int t) {
        a.push_back(t);
        auto it = ranges::lower_bound(a, t - 3000);
        return a.end() - it;
    }
};

// 方法二：堆
// time: O(logn), space: O(n)
class RecentCounter {
    priority_queue<int, vector<int>, greater<int>> hp;
public:
    int ping(int t) {
        hp.push(t);
        while(!hp.empty() && hp.top() < t - 3000) hp.pop();
        return hp.size();
    }
};

// 方法二：队列
// time: O(1), space: O(n)
class RecentCounter {
    queue<int> q;
public:
    int ping(int t) {
        q.push(t);
        while(!q.empty() && q.front() < t - 3000) q.pop();
        return q.size();
    }
};
