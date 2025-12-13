#include<iostream>
using namespace std;

const int N = 10;
bool st[N][N];
int n, m;
int ret;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
	if(x < 1 || x >= n || y < 1 || y >= m) {
		++ret;
		return;
	}
	
	st[x][y] = true;
	for(int k=0; k<4; ++k) {
		int i = x + dx[k], j = y + dy[k];
		if(!st[i][j]) dfs(i, j);
	}
	st[x][y] = false;
}

int main() {
	cin >> n >> m;
	
	//从非四角的边界点出发，不经过边界，到达另一个边界
	//ret=(x1+y1+x2+y2)/2=x1+y1
	
	//从左出发
	for(int i=1; i<n; ++i) {
		st[i][0] = true;
		dfs(i, 1);
		st[i][0] = false;
	}
	//从上出发
	for(int j=1; j<m; ++j) {
		st[0][j] = true;
		dfs(1, j);
		st[0][j] = false;
	}
	
	cout << ret << endl;
	
	return 0;
}
