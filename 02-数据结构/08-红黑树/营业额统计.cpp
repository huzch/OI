#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef long long LL;
const int INF = 1e7 + 10;
set<int> mp;
LL ret;
int n;

int main() {
	cin >> n;
	cin >> ret; mp.insert(ret);
	mp.insert(-INF); mp.insert(INF);
	for(int i=2; i<=n; ++i) {
		int x; cin >> x;
		auto it = mp.lower_bound(x);
		int y = *it, z = *--it;
		ret += min(abs(x - y), abs(x - z));
		mp.insert(x);
	}
	cout << ret << endl;
	return 0;
}
