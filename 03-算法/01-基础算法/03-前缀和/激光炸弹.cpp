#include <iostream>
using namespace std;

const int N = 5e3 + 10;
typedef long long LL;
LL f[N][N];

int main() {
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		int x, y, v; cin >> x >> y >> v;
		//同一位置可能有多个目标
		f[x + 1][y + 1] += v;
	}

	n = 5001;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
		}
	}

	//枚举爆炸范围的右下角
	LL ret = 0;
	m = min(m, n);
	for(int i=m; i<=n; ++i) {
		for(int j=m; j<=n; ++j) {
			LL sum = f[i][j] - f[i][j - m] - f[i - m][j] + f[i - m][j - m];
			ret = max(ret, sum);
		}
	}
	cout << ret << endl;

	return 0;
}
