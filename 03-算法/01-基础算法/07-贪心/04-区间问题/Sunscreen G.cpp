#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3e3;
struct node1 {
	int l, r;
}a[N];
struct node2 {
	int s, c;
}b[N];

int main() {
	int C, L; cin >> C >> L;
	for(int i=1; i<=C; ++i) {
		cin >> a[i].l >> a[i].r;
	}
	for(int i=1; i<=L; ++i) {
		cin >> b[i].s >> b[i].c;
	}

	//不断尝试不同组合，得出奶牛左端点降序+从大到小给出防晒霜
	sort(a + 1, a + C + 1, [](node1& x, node1& y) {
		return x.l > y.l;
	});
	sort(b + 1, b + L + 1, [](node2& x, node2& y) {
		return x.s > y.s;
	});

	//奶牛
	int ret = 0;
	for(int i=1; i<=C; ++i) {
		//防晒霜
		for(int j=1; j<=L; ++j) {
			if(b[j].s > a[i].r) continue;
			if(b[j].s < a[i].l) break;
			if(b[j].c == 0) continue;
			--b[j].c;
			++ret;
			break;
		}
	}
	cout << ret << endl;

	return 0;
}
