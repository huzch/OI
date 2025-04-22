#include <iostream>
using namespace std;

const int N = 1e5 + 10;
typedef long long LL;
LL f[N];

int main() {
	int n, m; cin >> n >> m;
	int x; cin >> x;
	//利用差分求出每段铁路的经过次数
	//此时差分数组每个下标对应每条铁路
	for(int i=2; i<=m; ++i) {
		int y; cin >> y;
		// x->y
		if(x < y) {
			f[x]++, f[y]--;
		}
		else {
			f[y]++, f[x]--;
		}
		x = y;
	}

	//还原数组
	LL ret = 0;
	for(int i=1; i<n; ++i) {
		f[i] += f[i - 1];
		int a, b, c; cin >> a >> b >> c;
		ret += min(a * f[i], c + b * f[i]);
	}
	cout << ret << endl;

	return 0;
}
