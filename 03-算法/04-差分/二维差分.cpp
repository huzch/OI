#include <iostream>
using namespace std;

const int N = 1e3 + 10;
typedef long long LL;
LL f[N][N];

void insert(int x1, int y1, int x2, int y2, int k) {
	f[x1][y1] += k;
	f[x2 + 1][y1] -= k;
	f[x1][y2 + 1] -= k;
	f[x2 + 1][y2 + 1] += k;
}

int main() {
	int n, m, q; cin >> n >> m >> q;
	//生成差分矩阵
	for(int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			LL x; cin >> x;
			insert(i, j, i, j, x);
		}
	}

	//进行差分操作
	while(q--) {
		int x1, y1, x2, y2, k; cin >> x1 >> y1 >> x2 >> y2 >> k;
		insert(x1, y1, x2, y2, k);
	}

	//还原差分矩阵 --- 前缀和
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			f[i][j] = f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
			cout << f[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
