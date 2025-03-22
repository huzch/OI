#include <iostream>
using namespace std;

const int N = 300;
char l[N], r[N];
int n;
char root, t;

void dfs(char u) {
	if(u == '*') return;
	cout << u;
	dfs(l[u]);
	dfs(r[u]);
}

int main() {
	cin >> n;
	cin >> root >> l[root] >> r[root];
	for(int i=2; i<=n; ++i) {
		cin >> t >> l[t] >> r[t];
	}

	dfs(root);

	return 0;
}
