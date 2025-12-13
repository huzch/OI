#include<iostream>
#include<vector>
#include<climits>
using namespace std;

typedef pair<int, int> PII;
const int INF = INT_MAX;
const int N = 1e4 + 10;
vector<PII> edges[N];
int dist[N];
int n, m, s;

void bf() {
	for(int i=1; i<=n; ++i) dist[i] = INF;
	dist[s] = 0;
	
	for(int i=1; i<n; ++i) {
		bool flag = false;
		for(int u=1; u<=n; ++u) {
			//正无穷再加一个数会溢出，变成负数，所以舍弃
			if(dist[u] == INF) continue;
			for(auto& kv: edges[u]) {
				int v = kv.first, w = kv.second;
				if(dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					flag = true;
				}
			}
		}
		if(!flag) break;
	}
	
	for(int i=1; i<=n; ++i) cout << dist[i] << " ";
}

int main() {
	cin >> n >> m >> s;
	for(int i=1; i<=m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edges[u].push_back({v, w});
	}
	
	bf();
	
	return 0;
}
