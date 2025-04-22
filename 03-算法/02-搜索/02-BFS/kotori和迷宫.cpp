#include<iostream>
#include<queue>
using namespace std;

const int N = 40;
struct node {
    int x, y;
};
char a[N][N];
int dist[N][N];
bool st[N][N];
int n, m;
int sx, sy;
int ret, cnt;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs() {
    queue<node> q;
    st[sx][sy] = true;
    q.push({sx, sy});

    while(q.size()) {
        auto t = q.front(); q.pop();
        int i = t.x, j = t.y;
        
        for(int k=0; k<4; ++k) {
        	int x = i + dx[k], y = j + dy[k];
        	if(x < 1 || x > n || y < 1 || y > m) continue;
        	if(st[x][y] || a[x][y] == '*') continue;
        	
        	st[x][y] = true;
    		dist[x][y] = dist[i][j] + 1;
    		if(a[x][y] == '.') q.push({x, y});
			else {
				ret = min(ret, dist[x][y]);
				++cnt;
			}
		}
    }
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            cin >> a[i][j];
            if(a[i][j] == 'k') sx = i, sy = j;
        }
    }

	ret = n * m;
    bfs();
    
    if(cnt == 0) cout << -1 << endl;
    else cout << cnt << " " << ret << endl;

    return 0;
}
