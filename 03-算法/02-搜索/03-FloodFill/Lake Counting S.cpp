#include<iostream>
using namespace std;

const int N = 110;
char a[N][N];
bool st[N][N];
int n, m;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

void dfs(int i, int j) {
	st[i][j] = true;
	for(int k=0; k<8; ++k) {
		int x = i + dx[k], y = j + dy[k];
		if(x >= 1 && x <= n && y >= 1 && y <= m
		&& !st[x][y] && a[x][y] == 'W') {
			dfs(x, y);
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cin >> a[i][j];
		}
	}
	
	int ret = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			if(!st[i][j] && a[i][j] == 'W') {
				dfs(i, j);
				++ret;
			}
		}
	}
	cout << ret << endl;
	
	return 0;
}
