//解法二：二分
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
int a[N];
int m, n;

int find(int x) {
	int l = 1, r = m;
	while(l < r) {
		int mid = l + (r - l) / 2;
		if(a[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	cin >> m >> n;
	for(int i=1; i<=m; i++) cin >> a[i];
	sort(a + 1, a + m + 1);

	//增加左护法，避免选中a[0]
	a[0] = -INF;

	LL ret = 0;
	for(int i=1; i<=n; i++) {
		int x; cin >> x;
		int pos = find(x);
		ret += min(abs(a[pos] - x), abs(a[pos - 1] - x));
	}
	cout << ret << endl;

	return 0;
}




//解法一：set
// #include <algorithm>
// #include <cstdlib>
// #include <iostream>
// #include <set>
// using namespace std;
//
// typedef long long LL;
//
// int main() {
// 	int m, n; cin >> m >> n;
// 	set<int> s;
// 	for (int i=1; i<=m; i++) {
// 	    int x; cin >> x;
// 		s.insert(x);
// 	}
//
// 	LL ret = 0;
// 	for (int i=1; i<=n; i++) {
// 	    int x; cin >> x;
// 		auto it = s.lower_bound(x);
// 		int r = *it, l = *--it;
// 		ret += min(abs(r - x), abs(l - x));
// 	}
// 	cout << ret << endl;
//
// 	return 0;
// }
