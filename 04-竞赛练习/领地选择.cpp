#include<iostream>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
LL f[N][N];
int n, m, c;

int main() {
	cin >> n >> m >> c;
	//创建前缀和矩阵
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> f[i][j];
			f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
		}
	}
	
	//枚举右下角坐标
	int x = -1, y = -1;
	LL ret = -INF;
	for(int x2=c; x2<=n; ++x2) {
		for(int y2=c; y2<=n; ++y2) {
			int x1 = x2 - c + 1, y1 = y2 - c + 1;
			LL sum = f[x2][y2] - f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1];
			if(ret < sum) {
				ret = sum;
				x = x1, y = y1;
			}
		}
	}
	
	cout << x << " " << y << endl;
	
	return 0;
}
