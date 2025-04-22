#include<iostream>
using namespace std;

const int N = 1e4 + 10;
//由于只用存储三个状态，所以用char即可满足1e8的空间
char f[N][N];
int T, p;

char dfs(int x, int y) {
	if(f[x][y] == '3') return '3';
	if(x == 0) return '1';
	if(y == 0) return '2';
	//表示该状态已访问
	f[x][y] = '3';
	return f[x][y] = dfs((x + y) % p, (x + y + y) % p);
}

int main() {
	cin >> T >> p;
	while(T--) {
		int x, y; cin >> x >> y;
		char ret = dfs(x, y);
		if(ret == '1') cout << 1 << endl;
		else if(ret == '2') cout << 2 << endl;
		else cout << "error" << endl;
	}
	return 0;
}
