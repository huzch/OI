#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
struct node {
	int t, d;
}a[N];

int main() {
	int n; cin >> n;
	int D = 0;
	for(int i=1; i<=n; ++i) {
		cin >> a[i].t >> a[i].d;
		D += a[i].d;
	}

	// sum1 = D1 + T1 * di + (T1 + 2 * ti) * dj + D2
	// sum2 = D1 + T1 * dj + (T1 + 2 * tj) * di + D2
	sort(a + 1, a + n + 1, [](node& x, node& y) {
		return x.t * y.d < y.t * x.d;
	});

	LL ret = 0;
	for(int i=1; i<=n; ++i) {
		D -= a[i].d;
		ret += D * 2 * a[i].t;
	}
	cout << ret << endl;

	return 0;
}
