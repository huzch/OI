// 方法一：堆(优先级队列)
// time: O(nlogk), space: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> hp;
        for(int i=0; i<k; ++i) hp.emplace(nums[i]);

        for(int i=k; i<nums.size(); ++i) {
            if(nums[i] > hp.top()) {
                hp.pop(); hp.emplace(nums[i]);
            }
        }
        return hp.top();
    }
};

// 方法二：堆(手动实现)
// time: O(nlogk), space: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=(k-1-1)/2; i>=0; --i) {
            down(nums, k, i);
        }

        for(int i=k; i<nums.size(); ++i) {
            if(nums[i] > nums[0]) {
                swap(nums[i], nums[0]);
                down(nums, k, 0);
            }
        }
        return nums[0];
    }

    // 大小为k的小堆
    void down(vector<int>& nums, int k, int parent) {
        int child = parent * 2 + 1;
        while(child < k) {
            if(child + 1 < k && nums[child] > nums[child + 1]) {
                ++child;
            }

            if(nums[parent] > nums[child]) {
                swap(nums[parent], nums[child]);
                parent = child;
                child = parent * 2 + 1;
            } else break;
        }
    }
};

// 方法二：快速选择
// time: O(n), space: O(1)
class Solution {
    int ret;
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        qSelect(nums, k, 0, nums.size() - 1);
        return ret;
    }

    void qSelect(vector<int>& nums, int k, int begin, int end) {
        if(begin > end) return;

        int key = getRandom(nums, begin, end);

        int l = begin - 1, r = end + 1, cur = begin;
        while(cur < r) {
            if(nums[cur] < key) swap(nums[++l], nums[cur++]);
            else if(nums[cur] > key) swap(nums[--r], nums[cur]);
            else ++cur;
        }

        int a = l - begin + 1, b = r - l - 1, c = end - r + 1;
        if(c >= k) qSelect(nums, k, r, end);
        else if(b + c >= k) ret = key;
        else qSelect(nums, k - b - c, begin, l);
    }

    int getRandom(vector<int>& nums, int begin, int end) {
        return nums[begin + random() % (end - begin + 1)];
    }
};
