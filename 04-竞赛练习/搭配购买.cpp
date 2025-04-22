#include<iostream>
#include<vector>
using namespace std;

const int N = 1e4 + 10;
int c[N], d[N];
int n, m, w;

vector<int> a[N];
bool st[N];
int cc[N], dd[N], k;

int f[N];

void dfs(int u) {
	st[u] = true;
	cc[k] += c[u];
	dd[k] += d[u];
	
	for(auto& v : a[u]) {
		if(!st[v]) dfs(v);
	}
}

int main() {
	cin >> n >> m >> w;
	for(int i=1; i<=n; ++i) {
		cin >> c[i] >> d[i];
	}
	
	for(int i=1; i<=m; ++i) {
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	for(int i=1; i<=n; ++i) {
		if(!st[i]) {
			++k;
			dfs(i);
		}
	}
	
	for(int i=1; i<=k; ++i) {
		for(int j=w; j>=cc[i]; --j) {
			f[j] = max(f[j], f[j-cc[i]] + dd[i]);
		}
	}
	cout << f[w] << endl;
	
	return 0;
}
