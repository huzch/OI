#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 110;
vector<int> edges[N];
int in[N];
int n;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		int x;
		while(cin >> x && x) {
			edges[i].push_back(x);
			++in[x];
		}
	}
	
	queue<int> q;
	for(int i=1; i<=n; ++i) {
		if(in[i] == 0) q.push(i);
	}
	
	while(q.size()) {
		auto u = q.front(); q.pop();
		cout << u << " ";
		
		for(int v: edges[u]) {
			--in[v];
			if(in[v] == 0) q.push(v);
		}
	}
	
	return 0;
}
