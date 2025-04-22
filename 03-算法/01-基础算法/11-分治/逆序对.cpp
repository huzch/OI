#include <iostream>
using namespace std;

typedef long long LL;
const int N = 5e5 + 10;
int a[N], tmp[N];
int n;

LL merge(int l, int r) {
	if(l == r) return 0;

	LL ret = 0;
	int mid = l + (r - l) / 2;
	ret += merge(l, mid);
	ret += merge(mid + 1, r);

	int cur1 = l, cur2 = mid + 1, k = l;
	while(cur1 <= mid && cur2 <= r) {
		if(a[cur1] <= a[cur2]) {
			tmp[k++] = a[cur1++];
		}
		else {
			ret += mid - cur1 + 1;
			tmp[k++] = a[cur2++];
		}
	}

	while(cur1 <= mid) tmp[k++] = a[cur1++];
	while(cur2 <= r) tmp[k++] = a[cur2++];
	for(int i=l; i<=r; ++i) a[i] = tmp[i];

	return ret;
}

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];

	cout << merge(1, n) << endl;

	return 0;
}
