#include <iostream>
using namespace std;

const int N = 1e5 + 10;
typedef long long LL;
LL f[N];

int main() {
	int n, m; cin >> n >> m;
	//根据差分性质创建
	for(int i=1; i<=n; ++i) {
		LL x; cin >> x;
		f[i] += x;
		f[i + 1] -= x;
	}

	//进行区间加减某数
	while(m--) {
		int l, r, k; cin >> l >> r >> k;
		f[l] += k;
		f[r + 1] -= k;
	}

	//还原数组
	for(int i=1; i<=n; ++i) {
		f[i] += f[i - 1];
		cout << f[i] << " ";
	}
	return 0;
}
