//spfa
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1510;
vector<PII> edges[N];
int dist[N];
bool st[N];
int n, m;

void spfa() {
	memset(dist, 0x3f, sizeof dist);
	
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	st[1] = true;
	
	while(q.size()) {
		auto u = q.front(); q.pop();
		st[u] = false;
		
		for(auto& kv: edges[u]) {
			int v = kv.first, w = kv.second;
			if(dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				if(!st[v]) {
					q.push(v);
					st[v] = true;
				}
			}
		}
	}
	
	if(dist[n] == INF) cout << -1 << endl;
	else cout << -dist[n] << endl;
}

int main() {
	cin >> n >> m;
	for(int i=1; i<=m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edges[u].push_back({v, -w}); //将边权取反，用最短路算法
	}
	
	spfa();
	
	return 0;
}




////因为这题是有向无环图，并且u<v,所以能这样做
////拓扑排序+动态规划 --- O(m+n)
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//typedef long long LL;
//typedef pair<int, int> PII;
//const int INF = 0x3f3f3f3f;
//const int N = 1510;
//vector<PII> edges[N];
//int in[N];
//int n, m;
//
//queue<int> q;
//LL f[N];
//
//int main() {
//	cin >> n >> m;
//	for(int i=1; i<=m; ++i) {
//		int u, v, w; cin >> u >> v >> w;
//		edges[u].push_back({v, w});
//		++in[v];
//	}
//	
//	//防止入度为0但编号不是1的点干扰，先对它们做一次拓扑排序
//	for(int i=2; i<=n; ++i) {
//		if(in[i] == 0) q.push(i);
//		//因为边权有负数，所以求max要初始化为负无穷
//		f[i] = -INF;
//	}
//	
//	while(q.size()) {
//		auto u = q.front(); q.pop();
//		for(auto& kv: edges[u]) {
//			int v = kv.first, w = kv.second;
//			--in[v];
//			if(in[v] == 0) q.push(v);
//		}
//	}
//	
//	q.push(1);
//	
//	while(q.size()) {
//		auto u = q.front(); q.pop();
//		for(auto& kv: edges[u]) {
//			int v = kv.first, w = kv.second;
//			f[v] = max(f[v], f[u] + w);
//			--in[v];
//			if(in[v] == 0) q.push(v);
//		}
//	}
//	
//	if(f[n] == -INF) cout << -1 << endl;
//	else cout << f[n] << endl;
//	
//	return 0;
//}
