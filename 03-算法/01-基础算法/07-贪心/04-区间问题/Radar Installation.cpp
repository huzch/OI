#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int N = 1e3 + 10;
struct node {
	double l, r;
}a[N];
int n;
double d;

int main() {
	int cnt = 1;
	while(cin >> n >> d) {
		if(n == 0 && d == 0) break;

		bool flag = true;
		for(int i=1; i<=n; ++i) {
			double x, y; cin >> x >> y;
			if(abs(y) > abs(d)) {
				flag = false;
			}
			double l = sqrt(d * d - y * y);
			a[i].l = x - l, a[i].r = x + l;
		}
		//无解
		if(!flag) {
			printf("Case %d: %d\n", cnt, -1);
			++cnt;
			continue;
		}

		sort(a + 1, a + n + 1, [](node& x, node& y){
			return x.l < y.l;
		});

		int ret = 1;
		double r = a[1].r;
		for(int i=2; i<=n; ++i) {
			if(a[i].l <= r) {
				r = min(r, a[i].r);
			}
			else {
				r = a[i].r;
				++ret;
			}
		}
		printf("Case %d: %d\n", cnt, ret);
		++cnt;
	}
	
	return 0;
}
