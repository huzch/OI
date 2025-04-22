#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e3 + 10;
int edges[N][N];
int dist[N];
bool st[N];
int n, m;
LL ret;

void dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	dist[1] = 0;
	
	priority_queue<PII, vector<PII>, greater<PII>> hp;
	hp.push({dist[1], 1});

	while(hp.size()) {
		auto t = hp.top(); hp.pop();
		int u = t.second;
		st[u] = true;
		
		for(int v=1; v<=n; ++v) {
			int w = edges[u][v];
			if(!st[v] && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				hp.push({dist[v], v});
			}
		}
	}
}

int main() {
	cin >> n >> m;
	memset(edges, 0x3f, sizeof edges);
	for(int i=1; i<=m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edges[u][v] = min(edges[u][v], w); //处理重边
	}
	
	dijkstra();
	
	for(int i=1; i<=n; ++i) ret += dist[i];
	
	//反向建图，计算返回的最短路
	for(int i=1; i<=n; ++i) {
		for(int j=i+1; j<=n; ++j) {
			swap(edges[i][j], edges[j][i]);
		}
	}
	
	dijkstra();
	
	for(int i=1; i<=n; ++i) ret += dist[i];
	cout << ret << endl;
	
	return 0;
}
