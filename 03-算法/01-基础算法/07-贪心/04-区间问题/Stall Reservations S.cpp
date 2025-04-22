#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int N = 5e4 + 10;
struct node1 {
	int l, r, i; //奶牛产奶左右区间，奶牛编号
}a[N];
struct node2 {
	int t, i; //最小时间，牛棚编号
	bool operator<(const node2& x) const {
		return t > x.t;
	}
};
int ret[N];

priority_queue<node2> hp;

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i].l >> a[i].r;
		a[i].i = i;
	}
	sort(a + 1, a + n + 1, [](node1& x, node1& y) {
		return x.l < y.l;
	});

	int k = 1; //牛棚数量
	ret[a[1].i] = 1; //第i号奶牛对应的牛棚
	hp.push({a[1].r, 1});
	for(int i=2; i<=n; ++i) {
		if(a[i].l <= hp.top().t) {
			//新开一个牛棚
			ret[a[i].i] = ++k;
			hp.push({a[i].r, k});
		}
		else {
			//使用原有牛棚
			auto t = hp.top(); hp.pop();
			ret[a[i].i] = t.i;
			hp.push({a[i].r, t.i});
		}
	}

	cout << k << endl;
	for(int i=1; i<=n; ++i) cout << ret[i] << endl;

	return 0;
}
