#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 5e3 + 10;
const int MOD = 80112002;
vector<int> edges[N];
int in[N], out[N];
int f[N]; //f[i]:到达i结点的食物链数量
int n, m;

int main() {
	cin >> n >> m;
	for(int i=1; i<=m; ++i) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		++out[a], ++in[b];
	}
	
	queue<int> q;
	for(int i=1; i<=n; ++i) {
		if(in[i] == 0) {
			q.push(i);
			f[i] = 1;
		}
	}
	
	while(q.size()) {
		int u = q.front(); q.pop();
		
		for(int v: edges[u]) {
			f[v] = (f[v] + f[u]) % MOD;
			--in[v];
			if(in[v] == 0) q.push(v);
		}
	}
	
	int ret = 0;
	for(int i=1; i<=n; ++i) {
		if(out[i] == 0) ret = (ret + f[i]) % MOD;
	}
	cout << ret << endl;
	
	return 0;
}
