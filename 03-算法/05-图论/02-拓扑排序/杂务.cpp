#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1e4 + 10;
vector<int> edges[N];
int in[N];
int t[N];
int f[N]; //f[i]:从初始点完成到i结点时，所花的最短时间
int n;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		int u, time, v; cin >> u >> time;
		t[u] = time;
		while(cin >> v && v) {
			edges[v].push_back(u);
			++in[u];
		}
	}
	
	queue<int> q;
	for(int i=1; i<=n; ++i) {
		if(in[i] == 0) {
			q.push(i);
			f[i] = t[i];
		}
	}
	
	while(q.size()) {
		int u = q.front(); q.pop();
		
		for(int v: edges[u]) {
			f[v] = max(f[v], f[u] + t[v]);
			--in[v];
			if(in[v] == 0) q.push(v);
		}
	}
	
 	int ret = 0;
	for(int i=1; i<=n; ++i) {
		ret = max(ret, f[i]);
	}
	cout << ret << endl;
	
	return 0;
}
