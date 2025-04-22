#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
int a[N];

int dfs(int l, int r) {
	if(l == r) return a[l];

	int mid = l + (r - l) / 2;
	int ret = max(dfs(l, mid), dfs(mid + 1, r));

	//一左一右
	int lmax = -INF, rmax = -INF;
	int sum = 0;
	for(int i=mid; i>=l; --i) {
		sum += a[i];
		lmax = max(lmax, sum);
	}
	sum = 0;
	for(int i=mid+1; i<=r; ++i) {
		sum += a[i];
		rmax = max(rmax, sum);
	}
	ret = max(ret, lmax + rmax);

	return ret;
}

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];

	cout << dfs(1, n) << endl;

	return 0;
}
