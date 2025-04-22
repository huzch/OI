#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3e4 + 10;
int a[N];

int main() {
	int w, n; cin >> w >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);

	int ret = 0;
	int l = 1, r = n;
	while(l <= r) {
		if(a[l] + a[r] <= w) ++l, --r;
		else --r;
		++ret;
	}
	cout << ret << endl;

	return 0;
}
