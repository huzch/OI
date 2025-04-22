#include <iostream>
using namespace std;

const int N = (1 << 11);
int f[N];

void dfs(int l, int r) {
	if(l > r) return;

	//判断类型
	char ret;
	int sum = f[r] - f[l - 1];
	if(sum == r - l + 1) ret = 'I';
	else if(sum == 0) ret = 'B';
	else ret = 'F';

	if(l == r) {
		cout << ret;
		return;
	}

	int mid = l + (r - l) / 2;
	dfs(l, mid); dfs(mid + 1, r);
	cout << ret;
}

int main() {
	int n; cin >> n;
	n = (1 << n);
	for(int i=1; i<=n; ++i) {
		char ch; cin >> ch;
		//前缀和，优化时间复杂度
		f[i] = f[i - 1] + ch - '0';
	}

	dfs(1, n);

	return 0;
}
