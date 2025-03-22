#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 110;
vector<int> edges[N];
int pa[N], dist[N];
int n;

int dfs(int u) {
	int ret = 0;
	for(int v : edges[u]) {
		ret = max(ret, dfs(v));
	}
	return ret + 1;
}

int bfs() {
	queue<int> q;
	q.push(1);

	int ret = 0;
	while(q.size()) {
		int sz = q.size();
		ret = max(ret, sz);
		while(sz--) {
			int u = q.front(); q.pop();
			for(int v : edges[u]) {
				q.push(v);
			}
		}
	}
	return ret;
}

int main() {
	cin >> n;
	for(int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		edges[u].push_back(v);
		pa[v] = u;
	}

	cout << dfs(1) << endl;
	cout << bfs() << endl;

	int x, y; cin >> x >> y;
	while(x != 1) {
		dist[pa[x]] = dist[x] + 1;
		x = pa[x];
	}
	int len = 0;
	while(y != 1 && dist[y] == 0) {
		++len;
		y = pa[y];
	}
	cout << dist[y] * 2 + len << endl;

	return 0;
}
