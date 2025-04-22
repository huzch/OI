#include<iostream>
using namespace std;

typedef long long LL;
const int N = 110;
int a[N][N];
int n, m;

LL f[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

LL dfs(int i, int j) {
	if(f[i][j]) return f[i][j];
	
	for(int k=0; k<4; ++k) {
		int x = i + dx[k], y = j + dy[k];
		if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] < a[i][j]) {
			f[i][j] = max(f[i][j], dfs(x, y) + 1);
		}
	}
	return f[i][j];
}

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cin >> a[i][j];
		}
	}
	
	LL ret = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			ret = max(ret, dfs(i, j));
		}
	}
	cout << ret + 1 << endl;
	
	return 0;
}
