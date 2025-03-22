#include <iostream>
using namespace std;

const int N = 1e3 + 10;
typedef long long LL;
LL f[N][N];

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			cin >> f[i][j];
			f[i][j] += f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1];
		}
	}

	while(q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		LL sum = f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
		cout << sum << endl;
	}

	return 0;
}
