//二分答案+暴搜
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
int a[N][N];
int n, m;

struct node {
	int x, y;
};
bool st[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

//判断是否能在限定的伤害值走到终点
bool bfs(int ret) {
	memset(st, 0, sizeof st);
	
	queue<node> q;
	for(int j=1; j<=m; ++j) {
		q.push({1, j});
		st[1][j] = true;
	}

	while(q.size()) {
		auto t = q.front(); q.pop();
		int i = t.x, j = t.y;
		
		for(int k=0; k<4; ++k) {
			int x = i + dx[k], y = j + dy[k];
			if(x >= 1 && x <= n && y >= 1 && y <= m && !st[x][y] && a[x][y] <= ret) {
				if(x == n) return true;
				else {
					q.push({x, y});
					st[x][y] = true;
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cin >> a[i][j];
		}
	}
	
	//最大值最小问题，二分枚举伤害值
	int l = 1, r = 1e3;
	while(l < r) {
		int mid = l + (r - l) / 2;
		if(bfs(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	
	return 0;
}
