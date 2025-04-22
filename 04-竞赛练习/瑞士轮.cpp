#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 10;
int s[N], w[N];
int n, r, q;

struct node {
	int s, id;
}a[N], b[N], c[N]; //b为胜利组，c为失败组

int main() {
	cin >> n >> r >> q;
	for(int i=1; i<=n+n; ++i) cin >> s[i];
	for(int i=1; i<=n+n; ++i) cin >> w[i];

	for(int i=1; i<=n+n; ++i) a[i] = {s[i], i};
	sort(a + 1, a + n + n + 1, [](node& x, node& y) {
		if(x.s != y.s) return x.s > y.s;
		else return x.id < y.id;
	});

	while(r--) {
		//将比赛结果分为胜利组和失败组，每组满足单调递减
		int pos = 1;
		for(int i=1; i<=n+n; i+=2) {
			int id1 = a[i].id, id2 = a[i + 1].id;
			if(w[id1] > w[id2]) {
				++s[id1];
				b[pos] = {s[id1], id1};
				c[pos] = a[i + 1];
			}
			else {
				++s[id2];
				b[pos] = {s[id2], id2};
				c[pos] = a[i];
			}
			++pos;
		}
		
		//合并两个有序数组
		int cur1 = 1, cur2 = 1, k = 1;
		while(cur1 <= n && cur2 <= n) {
			int s1 = b[cur1].s, s2 = c[cur2].s;
			int id1 = b[cur1].id, id2 = c[cur2].id;
			if(s1 > s2 || (s1 == s2 && id1 < id2)) {
				a[k++] = b[cur1++];
			}
			else {
				a[k++] = c[cur2++];
			}
		}
		while(cur1 <= n) a[k++] = b[cur1++];
		while(cur2 <= n) a[k++] = c[cur2++];
	}
	
	cout << a[q].id << endl;

	return 0;
}




//模拟 --- 超时
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int N = 2e5 + 10;
//int s[N], w[N];
//int n, r, q;
//
//struct node {
//	int s, i;
//}a[N];
//
//int main() {
//	cin >> n >> r >> q;
//	n *= 2;
//	for(int i=1; i<=n; ++i) cin >> s[i];
//	for(int i=1; i<=n; ++i) cin >> w[i];
//	
//	for(int i=1; i<=n; ++i) a[i] = {s[i], i};
//	
//	while(r--) {
//		sort(a + 1, a + n + 1, [](node& x, node& y) {
//			if(x.s != y.s) return x.s > y.s;
//			else return x.i < y.i;
//		});
//
//		for(int i=1; i<=n; i+=2) {
//			int i1 = a[i].i, i2 = a[i + 1].i;
//			if(w[i1] > w[i2]) {
//				++s[i1];
//				a[i] = {s[i1], i1};
//			}
//			else {
//				++s[i2];
//				a[i + 1] = {s[i2], i2};
//			}
//		}
//	}
//	
//	sort(a + 1, a + n + 1, [](node& x, node& y) {
//		if(x.s != y.s) return x.s > y.s;
//		else return x.i < y.i;
//	});
//	cout << a[q].i << endl;
//	
//	return 0;
//}
