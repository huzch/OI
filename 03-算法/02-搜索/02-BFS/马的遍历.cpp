#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;

const int N = 410;
int a[N][N];
struct node {
	int x, y;
};
int n, m, x, y;

int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

void bfs() {
	queue<node> q;
	a[x][y] = 0;
	q.push({x, y});
	
	while(q.size()) {
		auto f = q.front(); q.pop();
  		int i = f.x, j = f.y;
		
		for(int k=0; k<8; ++k) {
			int x = i + dx[k], y = j + dy[k];
			if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == -1) {
				a[x][y] = a[i][j] + 1;
				q.push({x, y});
			}
		}
	}
}

int main() {
	cin >> n >> m >> x >> y;

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			a[i][j] = -1;
		}
	}

	bfs();
	
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
