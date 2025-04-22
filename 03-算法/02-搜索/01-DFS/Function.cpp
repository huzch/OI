#include<iostream>
using namespace std;

typedef long long LL;
const int N = 30;
LL f[N][N][N];
LL x, y, z;

LL dfs(LL a, LL b, LL c) {
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	else if(a > 20 || b > 20 || c > 20) return dfs(20, 20, 20);
	
	if(f[a][b][c]) return f[a][b][c];
	if(a < b && b < c) {
		f[a][b][c] = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
	}
	else {
		f[a][b][c] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
	}
	return f[a][b][c];
}

int main() {
	while(cin >> x >> y >> z) {
		//因为解决同一个问题，所以不需要清空数据
		if(x == -1 && y == -1 && z == -1) break;
		LL ret = dfs(x, y, z);
		printf("w(%lld, %lld, %lld) = %lld\n", x, y, z, ret);
	}
	return 0;
}
