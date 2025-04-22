#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
char a[N][N];
int n, m;

struct node {
	int x, y;
};
int dist[4][N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

//多源01bfs
void bfs(int num) {
	deque<node> q;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			if(a[i][j] == num + '0') {
				q.push_back({i, j});
				dist[num][i][j] = 0;
			}
		}
	}
	
	while(q.size()) {
		auto t = q.front(); q.pop_front();
		int i = t.x, j = t.y;
		
		for(int k=0; k<4; ++k) {
			int x = i + dx[k], y = j + dy[k];
			if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '#') {
				int w = (a[x][y] == '.' ? 1 : 0);
				if(dist[num][x][y] == -1) {
					if(w == 0) q.push_front({x, y});
					else q.push_back({x, y});
					dist[num][x][y] = dist[num][i][j] + w;
				}
				else if(dist[num][i][j] + w < dist[num][x][y]) {
					dist[num][x][y] = dist[num][i][j] + w;
				}
			}
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
	
	//正难则反，暴搜3个国家到每个格子的最短距离
	memset(dist, -1, sizeof dist);
	bfs(1); bfs(2); bfs(3);
	
	int ret = INF;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			if(a[i][j] == '#') continue;
			int x = dist[1][i][j], y = dist[2][i][j], z = dist[3][i][j];
			
			if(x == -1 || y == -1 || z == -1) continue;
			
			if(a[i][j] == '.') ret = min(ret, x + y + z - 2);
			else ret = min(ret, x + y + z);
		}
	}
	
	if(ret != INF) cout << ret << endl;
	else cout << -1 << endl;
	
	return 0;
}
