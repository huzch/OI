#include <iostream>
using namespace std;

const int N = 10;
int n = 9;
int a[N][N];
bool row[N][N], col[N][N], st[N][N][N];

// bool dfs(int i, int j) {
// 	if(j == n) ++i, j = 0;
// 	if(i == n) return true;
// 	if(a[i][j]) return dfs(i, j + 1);
//
// 	for(int x=1; x<=n; ++x) {
// 		if(row[i][x] || col[j][x] || st[i/3][j/3][x]) continue;
// 		row[i][x] = col[j][x] = st[i/3][j/3][x] = true;
// 		a[i][j] = x;
// 		if(dfs(i, j + 1)) return true;
// 		a[i][j] = 0;
// 		row[i][x] = col[j][x] = st[i/3][j/3][x] = false;
// 	}
// 	return false;
// }

bool dfs(int x) {
	for(int i=x; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(a[i][j]) continue;
			for(int k=1; k<=9; ++k) {
				if(row[i][k] || col[j][k] || st[i/3][j/3][k]) continue;
				row[i][k] = col[j][k] = st[i/3][j/3][k] = true;
				a[i][j] = k;
				if(dfs(i)) return true;
				a[i][j] = 0;
				row[i][k] = col[j][k] = st[i/3][j/3][k] = false;
			}
			return false;
		}
	}
	return true;
}

int main() {
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cin >> a[i][j];
			int x = a[i][j];
			if(x == 0) continue;
			row[i][x] = col[j][x] = st[i/3][j/3][x] = true;
		}
	}

	dfs(0);

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
