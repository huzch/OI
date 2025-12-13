#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 510;
char a[N][N];
int n, m;
int x1, y1, x2, y2;

struct node {
	int x, y;
};
int dist[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs() {
	memset(dist, -1, sizeof dist);
	
	deque<node> q;
	q.push_back({x1, y1});
	dist[x1][y1] = 0;
	
	while(q.size()) {
		auto t = q.front(); q.pop_front();
		int i = t.x, j = t.y;
		//注意：01bfs要在出队列时剪枝，而不是像普通bfs在入队时剪枝
		if(i == x2 && j == y2) return;

		for(int k=0; k<4; ++k) {
			int x = i + dx[k], y = j + dy[k], w = 1;
			
			if(x >= 1 && x <= n && y >= 1 && y <= m) {
				if(a[i][j] == a[x][y]) w = 0;
				if(dist[x][y] == -1) {
					if(w == 0) q.push_front({x, y});
					else q.push_back({x, y});

					dist[x][y] = dist[i][j] + w;
				}
				else if(dist[i][j] + w < dist[x][y]) { //第二次遇到，松弛操作
					dist[x][y] = dist[i][j] + w;
				}
			}
		}
	}
}

int main() {
	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=m; ++j) {
				cin >> a[i][j];
			}
		}
		cin >> x1 >> y1 >> x2 >> y2;
		x1++, y1++, x2++, y2++;
		
		bfs();
		cout << dist[x2][y2] << endl;
	}
	return 0;
}
