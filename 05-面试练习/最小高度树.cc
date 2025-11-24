// 方法一：暴力枚举每点的高度（超时）
class Solution {
    vector<vector<int>> vv; //邻接表
    vector<bool> st;
public:
    // 计算以u为根节点的树高度
    int dfs(int u) {
        int h = 0;
        st[u] = true;
        for(int v: vv[u]) {
            if(!st[v]) h = max(h, dfs(v) + 1);
        }
        st[u] = false;
        return h;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vv.resize(n); st.resize(n);
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            vv[u].emplace_back(v);
            vv[v].emplace_back(u);
        }

        int minh = n;
        vector<int> heights(n);
        for(int i=0; i<n; ++i) {
            heights[i] = dfs(i);
            minh = min(minh, heights[i]);
        }

        vector<int> ret;
        ret.reserve(n);
        for(int i=0; i<n; ++i) {
            if(heights[i] == minh) {
                ret.emplace_back(i);
            }
        }
        return ret;
    }
};

// 方法二：拓扑排序
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0}; //无边，特殊处理

        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            ++degree[u], ++degree[v];
        }

        queue<int> q;
        for(int i=0; i<n; ++i) {
            if(degree[i] == 1) q.emplace(i);
        }

        // 从周围向中心计算最小高度
        vector<int> ret;
        ret.reserve(n);
        while(!q.empty()) {
            ret.clear(); //每轮清空，只记录最后一轮
            int sz = q.size();
            for(int i=0; i<sz; ++i) {
                int u = q.front(); q.pop();
                for(int v: adj[u]) {
                    if(--degree[v] == 1) q.emplace(v);
                }
                ret.emplace_back(u);
            }
        }
        return ret;
    }
};
