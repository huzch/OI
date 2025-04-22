#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e3 + 10;

struct node {
	int index;
	int cnt;
}row[N], col[N];

int m, n, k, l, d;

bool cmp1(node& x, node& y) {
	return x.cnt > y.cnt;
}

bool cmp2(node& x, node& y) {
	return x.index < y.index;
}

int main() {
	cin >> m >> n >> k >> l >> d;
	for(int i=1; i<=m; ++i) row[i].index = i;
	for(int i=1; i<=n; ++i) col[i].index = i;

	//行列摆放独立，互不影响
	while(d--) {
		int x, y, p, q; cin >> x >> y >> p >> q;
		if(x == p) col[min(y, q)].cnt++;
		else row[min(x, p)].cnt++;
	}

	//按cnt进行从大到小排序
	sort(row + 1, row + n + 1, cmp1);
	sort(col + 1, col + n + 1, cmp1);

	//按index进行从小到大排序
	sort(row + 1, row + k + 1, cmp2);
	sort(col + 1, col + l + 1, cmp2);

	for(int i=1; i<=k; ++i) cout << row[i].index << " ";
	cout << endl;
	for(int i=1; i<=l; ++i) cout << col[i].index << " ";
	cout << endl;

	return 0;
}
