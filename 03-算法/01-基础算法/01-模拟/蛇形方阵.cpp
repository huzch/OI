#include <cstdio>
#include <iostream>
using namespace std;

const int N = 20;
int mat[N][N];
// direction vector
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
	int n; cin >> n;
	int x = 1, y = 1; // start point
	int pos = 0; // direction index
	int k = 1; // number to put
	while(k <= n * n) {
		mat[x][y] = k++;

		int a = x + dx[pos], b = y + dy[pos];
		if(a < 1 || a > n || b < 1 || b > n || mat[a][b]) {
			pos = (pos + 1) % 4;
			a = x + dx[pos], b = y + dy[pos];
		}
		
		x = a, y = b;
	}

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}





