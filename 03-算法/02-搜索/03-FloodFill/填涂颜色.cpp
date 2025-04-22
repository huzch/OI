#include<iostream>
using namespace std;

const int N = 40;
int a[N][N];
bool st[N][N];
int n;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int i, int j) {
	st[i][j] = true;
	for(int k=0; k<4; ++k) {
		int x = i + dx[k], y = j + dy[k];
		if(x >= 0 && x <= n + 1 && y >= 0 && y <= n + 1
		&& !st[x][y] && a[x][y] == a[i][j]) {
			dfs(x, y);
		}
	}
}

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> a[i][j];
		}
	}
	
	//四周包裹0，所以一次搜索即可将边界0全部标记
	dfs(0, 0);
	
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if(a[i][j] == 0 && !st[i][j]) {
				a[i][j] = 2;
			}
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
