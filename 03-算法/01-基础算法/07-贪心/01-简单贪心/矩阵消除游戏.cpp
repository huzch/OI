#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 20;
int a[N][N], col[N];
int n, m, k;

int calc(int x) {
	int cnt = 0;
	while(x) {
		x &= x - 1;
		++cnt;
	}
	return cnt;
}

int main() {
	cin >> n >> m >> k;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			cin >> a[i][j];
		}
	}

	//二进制枚举行的选法
	int ret = 0;
	for(int st=0; st<(1<<n); ++st) {
		int cnt = calc(st);
		//排除非法状态
		if(cnt > k) continue;

		memset(col, 0, sizeof col);
		int sum = 0;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<m; ++j) {
				if((st >> i) & 1) sum += a[i][j];
				else col[j] += a[i][j];
			}
		}

		//选取前k-cnt大的列和
		sort(col, col + m, [](int x, int y){
			return x > y;
		});
		//注意计算列和时有越界风险
		for(int i=0; i<min(k-cnt, m); ++i) sum += col[i];
		ret = max(ret, sum);
	}
	cout << ret << endl;

	return 0;
}
