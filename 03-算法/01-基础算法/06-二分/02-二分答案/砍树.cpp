#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
LL a[N];
LL n, m;

//计算高度为x时，得到的木材总长度
LL calc(int x) {
	LL cnt = 0;
	for(int i=1; i<=n; i++) {
		if(a[i] > x) cnt += a[i] - x;
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];

	int l = 0, r = 4e5;
	while(l < r) {
		int mid = l + (r - l + 1) / 2;
		if(calc(mid) >= m) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;

	return 0;
}
