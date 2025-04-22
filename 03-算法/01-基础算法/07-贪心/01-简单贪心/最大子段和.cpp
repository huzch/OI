#include <iostream>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
int a[N];

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];

	LL ret = -INF, sum = 0;
	for(int i=1; i<=n; ++i) {
		sum += a[i];
		ret = max(ret, sum);
		if(sum < 0) sum = 0;
	}
	cout << ret << endl;

	return 0;
}
