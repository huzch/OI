#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
typedef long long LL;
LL f[N];

int main() {
	int n; cin >> n;
	LL minsum = 0;
	LL ret = -INF;
	for (int i=1; i<=n; ++i) {
		cin >> f[i];
		f[i] += f[i - 1];
		//当前前缀和 - 之前最小前缀和 = 当前最大子段和
		ret = max(ret, f[i] - minsum);
		//更新前缀和中的最小值
		minsum = min(minsum, f[i]);
	}
	cout << ret << endl;
	return 0;
}
