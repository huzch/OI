#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 5e4 + 10;
struct node {
	int w, s;
}a[N];

int main() {
	int n; cin >> n;
	int W = 0;
	for(int i=1; i<=n; ++i) {
		cin >> a[i].w >> a[i].s;
		W += a[i].w;
	}

	//max(W + wj - si, W - sj) < max(W + wi - sj, W - si)
	//max(wj - si, -sj) < max(wi - sj, -si)
	//wj - si < wi - sj
	sort(a + 1, a + n + 1, [](node& x, node& y){
		return x.w + x.s > y.w + y.s;
	});

	int ret = -INF;
	for(int i=1; i<=n; ++i) {
		W -= a[i].w;
		ret = max(ret, W - a[i].s);
	}
	cout << ret << endl;

	return 0;
}
