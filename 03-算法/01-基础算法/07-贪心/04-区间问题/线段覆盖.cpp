#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
struct node {
	int l, r;
}a[N];

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i].l >> a[i].r;
	}

	//线段问题先排序
	sort(a + 1, a + n + 1, [](node& x, node& y) {
		return x.l < y.l;
	});

	int ret = 1;
	int r = a[1].r;
	for(int i=2; i<=n; ++i) {
		if(a[i].l < r) {
			r = min(r, a[i].r);
		}
		else {
			r = a[i].r;
			++ret;
		}
	}
	cout << ret << endl;

	return 0;
}
