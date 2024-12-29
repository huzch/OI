#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int l[N], r[N];
int n;

//preorder
void dfs1(int u) {
	cout << u << " ";
	if(l[u]) dfs1(l[u]);
	if(r[u]) dfs1(r[u]);
}

//inorder
void dfs2(int u) {
	if(l[u]) dfs1(l[u]);
	cout << u << " ";
	if(r[u]) dfs1(r[u]);
}

//postorder
void dfs3(int u) {
	if(l[u]) dfs1(l[u]);
	if(r[u]) dfs1(r[u]);
	cout << u << " ";
}

void bfs(int u) {
	queue<int> q;
	q.push(u);

	while(q.size()) {
		int u = q.front(); q.pop();
		cout << u << " ";

		if(l[u]) q.push(l[u]);
		if(r[u]) q.push(r[u]);
	}
}

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> l[i] >> r[i];
	}

	dfs1(1);
	cout << endl;

	dfs2(1);
	cout << endl;

	dfs3(1);
	cout << endl;

	bfs(1);
	cout << endl;

	return 0;
}
