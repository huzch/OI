#include<iostream>
using namespace std;

typedef long long LL;
const int MOD = 1e8;
const int N = 2e3 + 10;
const int M = 1e3 + 10;
int r[N];
//f[i][j]:在前i头奶牛中，队伍总能力为j时，所有的队伍组合数
//f[i][j]:在前i头奶牛中，队伍总能力模m为j时，所有的队伍组合数
LL f[N][M];
int n, m;

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i) cin >> r[i];
	
	f[0][0] = 1;
	for(int i=1; i<=n; ++i) {
		for(int j=0; j<m; ++j) {
			//模加模处理负数，因为负数也有意义所以不能舍弃
			f[i][j] = f[i - 1][j] + f[i - 1][((j - r[i] % m) + m) % m];
			f[i][j] %= MOD;
		}
	}
	//舍弃全都不选择的情况
	cout << f[n][0] - 1 << endl;
	
	return 0;
}
