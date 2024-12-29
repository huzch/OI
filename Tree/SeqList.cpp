#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> edges[N];
bool st[N];
int n;

void dfs(int u) {
	st[u] = true;
	cout << u << " ";
	for(int v : edges[u]) {
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

		for(int v : edges[u]) {
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
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs(1);
	cout << endl;

	memset(st, 0, sizeof st);

	bfs(1);
	cout << endl;

	return 0;
}
