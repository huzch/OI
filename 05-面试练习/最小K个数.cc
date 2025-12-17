// 方法一：排序
// time: O(nlogn), space: O(1)

// 方法二：堆（优先队列）
// 整体入堆
// time: O(nlogn), space: O(n)
// 维护大小为k的堆
// time: O(nlogk), space: O(k)
// 用堆排序思想建堆比直接插入堆更优
// k+(n-k)logk ? klogk+2(n-k)logk=(2n-k)logk
// k ? nlogk

// 方法三：快速选择
// time: O(n), space: O(1)
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        srand(time(0));
        qsort(arr, 0, arr.size() - 1, k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }

    void qsort(vector<int>& a, int begin, int end, int k) {
        if(begin >= end) return;

        int key = getrandom(a, begin, end);
        int l = begin - 1, r = end + 1, i = begin;
        while(i < r) {
            if(a[i] < key) swap(a[++l], a[i++]);
            else if(a[i] > key) swap(a[--r], a[i]);
            else ++i;
        }

        int x = l - begin + 1, y = r - l - 1;
        if(k <= x) qsort(a, begin, l, k);
        else if(k <= x + y) return;
        else qsort(a, r, end, k - x - y); //注意k的变化
    }

    int getrandom(vector<int>& a, int l, int r) {
        return a[l + random() % (r - l + 1)];
    }
};
