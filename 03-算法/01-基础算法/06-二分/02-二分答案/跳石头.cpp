#include <iostream>
using namespace std;

const int N = 5e4 + 10;
int a[N];
int l, n, m;

//最短跳跃距离为x时，移走的最大岩石数
int calc(int x) {
	int ret = 0;
	int i = 1, j = 1;
	while(j <= n + 2) {
		if(a[j] - a[i] >= x) {
			ret += j - i - 1;
			i = j;
		}
		++j;
	}
	//最后一步的距离若小于x，也要丢弃中间的岩石
	ret += j - i - 1;
	return ret;
}

int main() {
	cin >> l >> n >> m;
	for(int i=2; i<=n+1; ++i) cin >> a[i];
	a[n + 2] = l;

	//二分枚举最短跳跃距离
	int left = 1, right = l;
	while(left < right) {
		int mid = left + (right - left + 1) / 2;
		if(calc(mid) <= m) left = mid;
		else right = mid - 1;
	}
	cout << left << endl;

	return 0;
}
