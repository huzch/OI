#include <iostream>
using namespace std;

const int N = 1e3 + 10;
typedef long long LL;
LL f[N][N];

int main() {
	int n, m; cin >> n >> m;
	//生成差分矩阵
	for(int i=1; i<=m; ++i) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		f[x1][y1]++, f[x2 + 1][y1]--, f[x1][y2 + 1]--, f[x2 + 1][y2 + 1]++;
	}

	//还原差分矩阵 --- 前缀和
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			f[i][j] = f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
