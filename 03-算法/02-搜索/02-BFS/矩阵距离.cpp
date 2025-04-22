#include<iostream>
#include<queue>
using namespace std;

const int N = 1e3 + 10;
char a[N][N];
int n, m;

struct node {
	int x, y;
};
queue<node> q;
int dist[N][N];
bool st[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs() {
	while(q.size()) {
		auto t = q.front(); q.pop();
		int i = t.x, j = t.y;

		for(int k=0; k<4; ++k) {
			int x = i + dx[k], y = j + dy[k];
			if(x < 1 || x > n || y < 1 || y > m) continue;
			if(st[x][y]) continue;

			st[x][y] = true;
			dist[x][y] = dist[i][j] + 1;
			q.push({x, y});
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cin >> a[i][j];
			if(a[i][j] == '1') {
				q.push({i, j});
				st[i][j] = true;
			}
		}
	}

	bfs();

	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
