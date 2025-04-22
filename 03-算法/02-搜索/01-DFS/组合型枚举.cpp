#include <iostream>
using namespace std;

const int N = 30;
int path[N], k;
int n, m;

void dfs(int pos) {
	if(k == m) {
		for(int i=1; i<=k; ++i) {
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}

	for(int i=pos; i<=n; ++i) {
		path[++k] = i;
		dfs(i + 1);
		--k;
	}
}

int main() {
	cin >> n >> m;

	dfs(1);

	return 0;
}
