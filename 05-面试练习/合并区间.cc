class Solution {
    vector<vector<int>> ret;
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals);
        for(auto& val: intervals) {
            if(!ret.empty() && ret.back()[1] >= val[0]) {
                ret.back()[1] = max(ret.back()[1], val[1]);
            } else {
                ret.push_back(val);
            }
        }
        return ret;
    }
};

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end(), [](vector<int>& x, vector<int>& y) {
//             return x[0] < y[0];
//         });
//
//         int n = intervals.size();
//         vector<vector<int>> ret;
//         ret.reserve(n);
//         for(int i=0; i<n-1; ++i) {
//             int a = intervals[i][0], b = intervals[i][1];
//             int c = intervals[i + 1][0], d = intervals[i + 1][1];
//             if(b < c) { //固定不变的区间直接插入
//                 ret.emplace_back(intervals[i]);
//             } else if(b >= c && b < d) {
//                 intervals[i + 1][0] = a;
//             } else {
//                 intervals[i + 1][0] = a, intervals[i + 1][1] = b;
//             }
//         }
//         ret.emplace_back(intervals[n - 1]);
//
//         return ret;
//     }
// };
