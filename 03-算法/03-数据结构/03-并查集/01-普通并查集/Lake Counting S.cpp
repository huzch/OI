// 并查集
#include<iostream>
using namespace std;

const int N = 110;
char a[N][N];
int fa[N * N];
int n, m;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void un(int x, int y) {
	fa[find(x)] = find(y);
}

int main() {
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin >> a[i][j];
		}
	}
	
	for(int i=0; i<n*m; ++i) fa[i] = i;
	
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(a[i][j] == '.') continue;
			for(int k=0; k<8; ++k) {
				int x = i + dx[k], y = j + dy[k];
				if(x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 'W') {
					// 二维转一维
					un(i * m + j, x * m + y);
				}
			}
		}
	}
	
	int ret = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			int x = i * m + j;
			if(a[i][j] == 'W' && x == fa[x]) {
				++ret;
			}
		}
	}
	cout << ret << endl;
	
	return 0;
}




// dfs
//#include<iostream>
//using namespace std;
//
//const int N = 110;
//char a[N][N];
//bool st[N][N];
//int n, m;
//
//int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
//int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
//
//void dfs(int x, int y) {
//	st[x][y] = true;
//	for(int k=0; k<8; ++k) {
//		int i = x + dx[k], j = y + dy[k];
//		if(i >= 1 && i <= n && j >= 1 && j <= m
//		&& !st[i][j] && a[i][j] == 'W') {
//			dfs(i, j);
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	for(int i=1; i<=n; ++i) {
//		for(int j=1; j<=m; ++j) {
//			cin >> a[i][j];
//		}
//	}
//	
//	int ret = 0;
//	for(int i=1; i<=n; ++i) {
//		for(int j=1; j<=m; ++j) {
//			if(!st[i][j] && a[i][j] == 'W') {
//				dfs(i, j);
//				++ret;
//			}
//		}
//	}
//	cout << ret << endl;
//	
//	return 0;
//}
