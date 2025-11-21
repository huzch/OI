// 方法一：贪心+堆
// time: O(nlogn根号c) space: O(n)
// c为vat范围，即最大值
class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int n = bucket.size();
        priority_queue<pair<int, int>> pq; //大堆存储<次数,下标>
        int up_cnt = 0;
        for(int i=0; i<n; ++i) {
            if(vat[i] == 0) continue; //vat为0，蓄水次数为0，直接排除，不用入堆
                
            if(bucket[i] == 0) { //必须升级一次
                ++bucket[i]; ++up_cnt;
            }
            pq.emplace((vat[i] + bucket[i] - 1) / bucket[i], i); //简便的向上取整
        }

        // 蓄水代价：pq.top().first + up_cnt(up_cnt为升级水桶次数)
        if(pq.empty()) return 0;
        int total_cnt = INT_MAX;
        // 必备条件：up_cnt < total_cnt
        // 优化条件：1. cnt == 1终止（因为大堆顶部的蓄水次数为1，则代表所有的蓄水次数都为1，由于vat不为0，1就是最小次数）
        //         2. 每次循环升级不止1次，要升级到该组蓄水操作减1（因为升级1次蓄水次数可能不变）
        while(up_cnt < total_cnt) {
            auto [cnt, i] = pq.top(); pq.pop();
            //次数为cnt可能有多组，导致cnt不变而up_cnt增加
            //所以不能检测到代价变大就退出（陷入局部最优）
            //要达到全局最优必须全局记录最小代价
            total_cnt = min(total_cnt, cnt + up_cnt);
            if(cnt == 1) break;
            
            // 计算蓄水操作减1所需的升级次数
            int newbucket = (vat[i] + cnt - 2) / (cnt - 1);
            up_cnt += newbucket - bucket[i];
            bucket[i] = newbucket;
            pq.emplace((vat[i] + bucket[i] - 1) / bucket[i], i);
        }
        return total_cnt;
    }
};

// 方法二：贪心+枚举
// time: O(nc) space: O(n)
// c为vat范围，即最大值
class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int maxk = *max_element(vat.begin(), vat.end());
        if(maxk == 0) return 0; //vat为0，蓄水次数为0

        int total_cnt = INT_MAX, n = bucket.size();
        // 枚举蓄水次数，k<total_cnt优化剪枝
        for(int k=1; k<=maxk && k<total_cnt; ++k) {
            int up_cnt = 0;
            for(int i=0; i<n; ++i) {
                // 枚举的蓄水次数超过原本的蓄水次数时，会得到负数，不用记录
                up_cnt += max(0, (vat[i] + k - 1) / k - bucket[i]);
            }
            total_cnt = min(total_cnt, k + up_cnt);
        }
        return total_cnt;
    }
};
