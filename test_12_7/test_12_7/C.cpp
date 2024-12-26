//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//const int MOD = 1e9 + 7;
//vector<int> a, b;
//int n;
//unordered_map<string, int> mem;
//
//string GetStr(const vector<bool>& vis)
//{
//    string key = "";
//    for (int i = 1; i <= n; ++i)
//    {
//        key += (vis[i] ? '1' : '0');
//    }
//    return key;
//}
//
//int dfs(int pos, vector<bool>& vis)
//{
//    if (pos == n)
//    {
//        for (int i = 1; i <= n; ++i)
//        {
//            if (!vis[i]) return 0;
//        }
//        return 1;
//    }
//
//    string s = GetStr(vis);
//
//    if (mem.count(s)) return mem[s];
//
//    int cnt = 0;
//
//    if (!vis[a[pos]])
//    {
//        vis[a[pos]] = true;
//        cnt = (cnt + dfs(pos + 1, vis)) % MOD;
//        vis[a[pos]] = false;
//    }
//
//    if (!vis[b[pos]])
//    {
//        vis[b[pos]] = true;
//        cnt = (cnt + dfs(pos + 1, vis)) % MOD;
//        vis[b[pos]] = false;
//    }
//
//    mem[s] = cnt;
//    return cnt;
//}
//
//int main()
//{
//	cin >> n;
//	a.resize(n);
//	b.resize(n);
//	for (int i = 0; i < n; ++i) cin >> a[i];
//	for (int i = 0; i < n; ++i) cin >> b[i];
//    vector<bool> vis(n + 1, false);
//	cout << dfs(0, vis) << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<unordered_set>
//using namespace std;
//
//const int MOD = 1e9 + 7;
//vector<int> a, b;
//unordered_set<int> vis;
//int n, cnt;
//
//void dfs(int pos)
//{
//	if (pos == n)
//	{
//		if (vis.size() == n) cnt = (cnt + 1) % MOD;
//		return;
//	}
//
//	if (!vis.count(a[pos]))
//	{
//		vis.insert(a[pos]);
//		dfs(pos + 1);
//		vis.erase(a[pos]);
//	}
//
//	if (!vis.count(b[pos]))
//	{
//		vis.insert(b[pos]);
//		dfs(pos + 1);
//		vis.erase(b[pos]);
//	}
//}
//
//int main()
//{
//	cin >> n;
//	a.resize(n);
//	b.resize(n);
//	for (int i = 0; i < n; ++i) cin >> a[i];
//	for (int i = 0; i < n; ++i) cin >> b[i];
//	dfs(0);
//	cout << cnt << endl;
//	return 0;
//}