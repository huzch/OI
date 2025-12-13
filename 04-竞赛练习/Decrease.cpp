#include<iostream>
#include<cstdio>
using namespace std;

typedef long long LL;
const int N = 5e3 + 10;
LL f[N][N];
int n, m, k;

void insert(int x1, int y1, int x2, int y2, int k) {
	f[x1][y1] += k;
	f[x1][y2 + 1] -= k;
	f[x2 + 1][y1] -= k;
	f[x2 + 1][y2 + 1] += k;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	//原矩阵全为0转化为差分矩阵全为0
	for(int i=1; i<=m; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		insert(x, y, x, y, z);
	}
	
	//枚举子矩阵的左上角坐标
	LL ret = 0;
	for(int x1=1; x1<=n-k+1; ++x1) {
		for(int y1=1; y1<=n-k+1; ++y1) {
			ret += abs(f[x1][y1]);
			int x2 = x1 + k - 1, y2 = y1 + k - 1;
			insert(x1, y1, x2, y2, -f[x1][y1]);
		}
	}
	
	//判断是否无解
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if(f[i][j]) {
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%lld\n", ret);
	
	return 0;
}
