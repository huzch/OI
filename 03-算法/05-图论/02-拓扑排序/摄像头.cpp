#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 510;
vector<int> edges[N];
int in[N];
bool st[N]; //标记摄像头
int n;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		int x, m; cin >> x >> m;
		st[x] = true;
		while(m--) {
			int y; cin >> y;
			edges[x].push_back(y);
			++in[y];
		}
	}
	
	queue<int> q;
	for(int i=0; i<=500; ++i) {
		if(st[i] && in[i] == 0) q.push(i);
	}
	
	while(q.size()) {
		auto u = q.front(); q.pop();
		
		for(int v: edges[u]) {
			--in[v];
			if(st[v] && in[v] == 0) q.push(v);
		}
	}
	
	int cnt = 0;
	for(int i=0; i<=500; ++i) {
		if(st[i] && in[i] != 0) ++cnt;
	}
	
	if(cnt == 0) cout << "YES" << endl;
	else cout << cnt << endl;
	
	return 0;
}
