#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;
vector<PII> edges[N];
int dist[N];
//标记哪些结点已经确定最短路
bool st[N];
int n, m, s;

priority_queue<PII, vector<PII>, greater<PII>> hp;

void dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;
	hp.push({dist[s], s});

	while(hp.size()) {
		auto t = hp.top(); hp.pop();
		int u = t.second;
		st[u] = true;

		for(auto& kv: edges[u]) {
			int v = kv.first, w = kv.second;
			if(!st[v] && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				hp.push({dist[v], v});
			}
		}
	}

	for(int i=1; i<=n; ++i) cout << dist[i] << " ";
}

int main() {
	cin >> n >> m >> s;
	for(int i=1; i<=m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edges[u].push_back({v, w});
	}

	dijkstra();

	return 0;
}
