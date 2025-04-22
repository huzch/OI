#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int a[N];

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);

	LL ret = 0;
	for(int i=1; i<=n/2; ++i) {
		ret += a[n - i + 1] - a[i];
	}
	cout << ret << endl;

	return 0;
}
