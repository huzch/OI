#include <iostream>
using namespace std;

const int N = 5e6 + 10;
int a[N];
int n, k;
int ret, sum, cnt;

bool check(int x) {
	if(x <= 1) return false;
	//防溢出
	for(int i=2; i<=x/i; ++i) {
		if(x % i == 0) return false;
	}
	return true;
}

void dfs(int pos) {
	if(cnt == k) {
		if(check(sum)) ++ret;
		return;
	}

	for(int i=pos; i<=n; ++i) {
		sum += a[i];
		++cnt;
		dfs(i + 1);
		--cnt;
		sum -= a[i];
	}
}

int main() {
	cin >> n >> k;
	for(int i=1; i<=n; ++i) cin >> a[i];

	dfs(1);
	cout << ret << endl;

	return 0;
}
