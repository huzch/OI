#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

typedef pair<int, int> PII;
const int INF = INT_MAX;
const int N = 1e4 + 10;
vector<PII> edges[N];
int dist[N];
//标记哪些结点在队列中
bool st[N];
int n, m, s;

void spfa() {
	for(int i=1; i<=n; ++i) dist[i] = INF;
	dist[s] = 0;
	
	queue<int> q;
	q.push(s);
	st[s] = true;
	
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
	
	for(int i=1; i<=n; ++i) cout << dist[i] << " ";
}

int main() {
	cin >> n >> m >> s;
	for(int i=1; i<=m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edges[u].push_back({v, w});
	}

	spfa();

	return 0;
}
