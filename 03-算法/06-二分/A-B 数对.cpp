#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
int a[N];

int main() {
	int n, c; cin >> n >> c;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	
	//可通过枚举A来查找对应的B是否存在，B = A - C
	//最优解法：哈希表
	//此处使用二分，拓展思路
	sort(a + 1, a + n + 1);

	LL ret = 0;
	for(int i=1; i<=n; ++i) {
		int b = a[i] - c;
		auto it1 = lower_bound(a + 1, a + i + 1, b);
		auto it2 = upper_bound(a + 1, a + i + 1, b);
		ret += it2 - it1;
	}
	cout << ret << endl;

	return 0;
}
