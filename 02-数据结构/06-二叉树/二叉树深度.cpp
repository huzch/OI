#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int l[N], r[N];
int n;

int dfs(int root) {
	if(!root) return 0;

	int lH = dfs(l[root]);
	int rH = dfs(r[root]);
	return max(lH, rH) + 1;
}

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> l[i] >> r[i];
	}

	cout << dfs(1) << endl;

	return 0;
}
