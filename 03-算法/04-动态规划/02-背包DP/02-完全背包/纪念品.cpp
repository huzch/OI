//贪心+动态规划
//股票问题结论：任意一笔跨天的交易，都可以转换为连续的"当天买，隔天卖"的形式
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 110;
const int M = 1e4 + 10;
int p[N][N];
//f[i][j]:前i个纪念品中，花费不超过j时，所有的最大利润
LL f[M];
int t, n, m;

//完全背包
void solve(int v[], int w[]) {
	memset(f, 0, sizeof f);
	
	for(int i=1; i<=n; ++i) {
		for(int j=v[i]; j<=m; ++j) {
			f[j] = max(f[j], f[j - v[i]] + w[i] - v[i]);
		}
	}
	//本金变化
	m += f[m];
}

int main() {
	cin >> t >> n >> m;
	for(int i=1; i<=t; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> p[i][j];
		}
	}
	
	//贪心
	for(int i=1; i<t; ++i) {
		solve(p[i], p[i + 1]);
	}
	
	cout << m << endl;
	
	return 0;
}
