#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int a[N];
int n, k;

//计算小段长度为x时，切割的总段数
LL calc(int x) {
	LL cnt = 0;
	for(int i=1; i<=n; i++) {
		cnt += a[i] / x;
	}
	return cnt;
}

int main() {
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];

	//二分枚举段长
	int l = 0, r = 1e8;
	while(l < r) {
		int mid = l + (r - l + 1) / 2;
		//这里段数大于等于k都是合法的，我们要找合法中最接近k的，这样使得段长最大
		//段数越大，段长越小，所以大于等于区间在mid左边，小于区间在mid右边
		if(calc(mid) >= k) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;

	return 0;
}
