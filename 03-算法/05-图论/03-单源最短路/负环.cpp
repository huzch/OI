#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 2e3 + 10;
vector<PII> edges[N];
int dist[N];
bool st[N];
int cnt[N]; //表示源点到当前结点的步数
int n, m;

bool spfa() {
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);
	
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
				cnt[v] = cnt[u] + 1;
				
				if(cnt[v] == n) return true;
				if(!st[v]) {
					q.push(v);
					st[v] = true;
				}
			}
		}
	}
	
	return false;
}

int main() {
	int T; cin >> T;
	while(T--) {
		cin >> n >> m;
		//多组测试用例清空
		for(int i=1; i<=n; ++i) edges[i].clear();
		
		for(int i=1; i<=m; ++i) {
			int u, v, w; cin >> u >> v >> w;
			edges[u].push_back({v, w});
			if(w >= 0) edges[v].push_back({u, w});
		}
		
		if(spfa()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}




//bf
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//const int INF = 0x3f3f3f3f;
//const int N = 2e3 + 10;
//const int M = 3e3 + 10;
//struct node {
//	int u, v, w;
//}e[M * 2];
//int pos; //记录边数
//int dist[N];
//int n, m;
//
//bool bf() {
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	
//	bool flag = false;
//	//多进行一轮松弛，以判断负环
//	for(int i=1; i<=n; ++i) {
//		flag = false;
//		for(int j=1; j<=pos; ++j) {
//			int u = e[j].u, v = e[j].v, w = e[j].w;
//			if(dist[u] == INF) continue;
//			if(dist[u] + w < dist[v]) {
//				dist[v] = dist[u] + w;
//				flag = true;
//			}
//		}
//		if(!flag) break;
//	}
//	
//	return flag;
//}
//
//int main() {
//	int T; cin >> T;
//	while(T--) {
//		pos = 0; //多组测试用例清空
//		cin >> n >> m;
//		for(int i=1; i<=m; ++i) {
//			int u, v, w; cin >> u >> v >> w;
//			e[++pos] = {u, v, w};
//			if(w >= 0) e[++pos] = {v, u, w};
//		}
//		
//		if(bf()) cout << "YES" << endl;
//		else cout << "NO" << endl;
//	}
//	
//	return 0;
//}
