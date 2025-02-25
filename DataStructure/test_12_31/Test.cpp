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




















// #include <iostream>
// #include <unordered_map>
// using namespace std;
//
// string a, b;
// unordered_map<char, int> mp;
//
// void dfs(int l1, int r1, int l2, int r2) {
// 	if(l1 > r1) return;
//
// 	int p = mp[b[l2]];
// 	dfs(l1, p - 1, l2 + 1, p + l2 - l1);
// 	dfs(p + 1, r1, p + l2 - l1 + 1, r2);
// 	cout << b[l2];
// }
//
// int main() {
// 	cin >> a >> b;
// 	int n = a.size();
// 	for(int i=0; i<n; ++i) {
// 		mp[a[i]] = i;
// 	}
//
// 	dfs(0, n - 1, 0, n - 1);
// 	return 0;
// }

















// #include <iostream>
// #include <unordered_map>
// using namespace std;
//
// string a, b;
// unordered_map<char, int> mp;
//
// void dfs(int l1, int r1, int l2, int r2) {
// 	if(l1 > r1) return;
// 	//1.寻找根结点
// 	cout << b[r2];
// 	int p = mp[b[r2]];
// 	//2.划分左右子树
// 	dfs(l1, p - 1, l2, l2 + p - l1 - 1);
// 	dfs(p + 1, r1, l2 + p - l1, r2 - 1);
// }
//
// int main() {
// 	cin >> a >> b;
// 	int n = a.size();
// 	for(int i=0; i<n; ++i) {
// 		mp[a[i]] = i;
// 	}
//
// 	dfs(0, n - 1, 0, n - 1);
// 	return 0;
// }
//











// #include <algorithm>
// #include <iostream>
// using namespace std;
//
// const int N = 1e6 + 10;
// int l[N], r[N];
// int n;
//
// int dfs(int root) {
// 	if(!root) return 0;
//
// 	int lH = dfs(l[root]);
// 	int rH = dfs(r[root]);
// 	return max(lH, rH) + 1;
// }
//
// int main() {
// 	cin >> n;
// 	for(int i=1; i<=n; ++i) {
// 		cin >> l[i] >> r[i];
// 	}
//
// 	cout << dfs(1) << endl;
//
// 	return 0;
// }















// #include <iostream>
// using namespace std;
//
// const int N = 1e6 + 10;
// int l[N], r[N];
// int n;
//
// void dfs1(int root) {
// 	if(!root) return;
// 	cout << root << " ";
// 	dfs1(l[root]);
// 	dfs1(r[root]);
// }
//
// void dfs2(int root) {
// 	if(!root) return;
// 	dfs2(l[root]);
// 	cout << root << " ";
// 	dfs2(r[root]);
// }
//
// void dfs3(int root) {
// 	if(!root) return;
// 	dfs3(l[root]);
// 	dfs3(r[root]);
// 	cout << root << " ";
// }
//
// int main() {
// 	cin >> n;
// 	for(int i=1; i<=n; ++i) {
// 		cin >> l[i] >> r[i];
// 	}
//
// 	dfs1(1);
// 	cout << endl;
// 	dfs2(1);
// 	cout << endl;
// 	dfs3(1);
// 	cout << endl;
//
// 	return 0;
// }
