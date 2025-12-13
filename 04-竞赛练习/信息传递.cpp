#include<iostream>
#include<queue>
using namespace std;

const int N = 2e5 + 10;
int ne[N], in[N];
bool st[N];
int cnt;

void dfs(int x) {
	st[x] = true;
	++cnt;
	int y = ne[x];
	if(!st[y]) dfs(y);
}

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> ne[i];
		++in[ne[i]];
	}
	
	//利用拓扑排序标记非环结点
	queue<int> q;
	for(int i=1; i<=n; ++i) {
		if(in[i] == 0) q.push(i);
	}
	
	while(q.size()) {
		auto a = q.front(); q.pop();
		st[a] = true;
		int b = ne[a];
		--in[b];
		if(in[b] == 0) q.push(b);
	}
	
	//利用dfs在众多环中选取最小的
	int ret = n;
	for(int i=1; i<=n; ++i) {
		if(!st[i]) {
			cnt = 0;
			dfs(i);
			ret = min(ret, cnt);
		}
	}
	cout << ret << endl;
	
	return 0;
}


//#include<iostream>
//#include<vector>
//#include<unordered_set>
//using namespace std;
//
//const int N = 2e5 + 10;
//int a[N];
//
//int main() {
//	int n; cin >> n;
//	vector<unordered_set<int>> b(n + 1);
//	for(int i=1; i<=n; ++i) {
//		cin >> a[i];
//		b[i].insert(i);
//	}
//	
//	int cnt = 0;
//	while(1) {
//		++cnt;
//		vector<unordered_set<int>> c(b);
//		for(int i=1; i<=n; ++i) {
//			for(auto& x: b[i]) {
//				if(x == a[i]) {
//					cout << cnt << endl;
//					return 0;
//				}
//				c[a[i]].insert(x);
//			}
//		}
//		b = c;
//	}
//	return 0;
//}
