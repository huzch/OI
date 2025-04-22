// 解法一：贪心
// #include <algorithm>
// #include <iostream>
// using namespace std;
//
// typedef long long LL;
// const LL INF = 1e10;
// const int N = 2e4 + 10;
// struct node {
// 	LL l, r;
// }a[N];
//
// int main() {
// 	int n; cin >> n;
// 	for(int i=1; i<=n; ++i) {
// 		cin >> a[i].l >> a[i].r;
// 	}
//
// 	sort(a + 1, a + n + 1, [](node& x, node& y) {
// 		return x.l < y.l;
// 	});
// 	a[n + 1] = {INF, INF};
//
// 	LL ret = 0;
// 	LL l = a[1].l, r = a[1].r;
// 	for(int i=2; i<=n+1; ++i) {
// 		if(a[i].l <= r) r = max(r, a[i].r);
// 		else {
// 			ret += r - l;
// 			l = a[i].l, r = a[i].r;
// 		}
// 	}
// 	cout << ret << endl;
//
// 	return 0;
// }





//解法二：差分+离散化
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e4 + 10;
int a[N], b[N], n;
int disc[2 * N], pos;
int f[2 * N];

//二分
int find(int x) {
	int l = 1, r = pos;
	while(l < r) {
		int mid = l + (r - l) / 2;
		if(disc[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i] >> b[i];
		disc[++pos] = a[i], disc[++pos] = b[i];
	}

	//离散化：排序+去重
	sort(disc + 1, disc + pos + 1);
	pos = unique(disc + 1, disc + pos + 1) - (disc + 1);

	//差分
	for(int i=1; i<=n; ++i) {
		int l = find(a[i]), r = find(b[i]);
		f[l] += 1, f[r] -= 1;
	}

	//还原原数组：前缀和
	for(int i=1; i<=pos; ++i) {
		f[i] += f[i - 1];
	}

	//统计结果
	int ret = 0;
	for(int i=1; i<=pos; ++i) {
		int j = i;
		while(j <= pos && f[j] > 0) ++j;
		ret += disc[j] - disc[i];
		i = j;
	}
	cout << ret << endl;

	return 0;
}
