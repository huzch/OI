#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];
//f[i]:表示[1,i]的数组和
int f[N];

int main() {
	int n, q;
	cin >> n >> q;

	//使用前缀和数组下标从1开始，处理边界
	for (int i=1; i<=n; ++i) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}

	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << f[r] - f[l - 1] << endl;
	}

	return 0;
}
