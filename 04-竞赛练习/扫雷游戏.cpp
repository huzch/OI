#include<iostream>
using namespace std;

const int N = 110;
char a[N][N];
int n, m;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int count(int x, int y) {
	int ret = 0;
	for(int k=0; k<8; ++k) {
		int i = x + dx[k], j = y + dy[k];
		if(x >= 1 && x <= n && y >= 1 && y <= m) {
			if(a[i][j] == '*') ++ret;
		}
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cin >> a[i][j];
		}
	}
	
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			if(a[i][j] == '?') {
				a[i][j] = count(i, j) + '0';
			}
		}
	}
	
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cout << a[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
