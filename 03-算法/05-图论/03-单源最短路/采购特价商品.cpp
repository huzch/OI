#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

typedef pair<double, int> PDI;
typedef pair<double, double> PDD;
const int N = 110;
double edges[N][N];
double dist[N];
bool st[N];
unordered_map<int, PDD> mp;
int n, m, s, t;

double calc(int u, int v) {
	double x1 = mp[u].first, y1 = mp[u].second;
	double x2 = mp[v].first, y2 = mp[v].second;
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void dijkstra() {
	for(int i=1; i<=n; ++i) dist[i] = 1e10;
	dist[s] = 0;
	
	priority_queue<PDI, vector<PDI>, greater<PDI>> hp;
	hp.push({dist[s], s});
	
	while(hp.size()) {
		auto kv = hp.top(); hp.pop();
		int u = kv.second;
		st[u] = true;
		
		for(int v=1; v<=n; ++v) {
			double w = edges[u][v];
			if(!st[v] && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				hp.push({dist[v], v});
			}
		}
	}
	
	printf("%.2lf ", dist[t]);
}

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		double x, y; cin >> x >> y;
		mp[i] = {x, y};
	}
	
	cin >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			edges[i][j] = 1e10;
		}
	}
	for(int i=1; i<=m; ++i) {
		int u, v; cin >> u >> v;
		double d = calc(u, v);
		edges[u][v] = edges[v][u] = d;
	}
	
	cin >> s >> t;
	
	dijkstra();
	
	return 0;
}
