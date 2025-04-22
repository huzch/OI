#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int h[N], e[N*2], ne[N*2], id;
bool st[N];
int n;

void add(int u, int v) {
	e[++id] = v;
	ne[id] = h[u];
	h[u] = id;
}

void dfs(int u) {
	st[u] = true;
	cout << u << " ";
	for(int i=h[u]; i; i=ne[i]) {
		int v = e[i];
		if(!st[v]) {
			dfs(v);
		}
	}
}

void bfs(int u) {
	queue<int> q;
	q.push(u);
	st[u] = true;

	while(q.size()) {
		int u = q.front(); q.pop();
		cout << u << " ";

		for(int i=h[u]; i; i=ne[i]) {
			int v = e[i];
			if(!st[v]) {
				q.push(v);
				st[v] = true;
			}
		}
	}
}

int main() {
	cin >> n;
	for(int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		add(u, v); add(v, u);
	}

	dfs(1);
	cout << endl;

	memset(st, 0, sizeof st);

	bfs(1);
	cout << endl;

	return 0;
}
