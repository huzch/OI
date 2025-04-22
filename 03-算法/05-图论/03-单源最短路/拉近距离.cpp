#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
int edges[N][N];
int dist[N];
int cnt[N];
bool st[N];
int n, m;

bool spfa(int s) {
	memset(dist, 0x3f, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	memset(st, 0, sizeof st);
	dist[s] = 0;
	
	queue<int> q;
	q.push(s);
	st[s] = true;
	
	while(q.size()) {
		auto u = q.front(); q.pop();
		st[u] = false;
		
		for(int v=1; v<=n; ++v) {
			int w = edges[u][v];
			if(w == INF) continue;
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
	cin >> n >> m;
	memset(edges, 0x3f, sizeof edges);
	for(int i=1; i<=m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edges[u][v] = min(edges[u][v], -w); //重边
	}
	
	//爱情是双向奔赴的，所以要选择1到n和n到1最短路的最小值
	if(spfa(1)) cout << "Forever love" << endl;
	else {
		int t = dist[n];
		spfa(n);
		cout << min(t, dist[1]) << endl;
	}
	
	return 0;
}
