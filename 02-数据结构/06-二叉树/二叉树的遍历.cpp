#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int l[N], r[N];
int n;

void dfs1(int root) {
	if(!root) return;
	cout << root << " ";
	dfs1(l[root]);
	dfs1(r[root]);
}

void dfs2(int root) {
	if(!root) return;
	dfs2(l[root]);
	cout << root << " ";
	dfs2(r[root]);
}

void dfs3(int root) {
	if(!root) return;
	dfs3(l[root]);
	dfs3(r[root]);
	cout << root << " ";
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

	return 0;
}
