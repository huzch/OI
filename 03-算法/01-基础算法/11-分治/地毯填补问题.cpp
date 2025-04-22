#include <iostream>
using namespace std;

void dfs(int a, int b, int x, int y, int n) {
	if(n == 1) return;

	n /= 2;
	if(x < a + n && y < b + n) {
		cout << a + n << " " << b + n << " " << 1 << endl;
		dfs(a, b, x, y, n);
		dfs(a, b + n, a + n - 1, b + n, n);
		dfs(a + n, b, a + n, b + n - 1, n);
		dfs(a + n, b + n, a + n, b + n, n);
	}
	else if(x < a + n && y >= b + n) {
		cout << a + n << " " << b + n - 1 << " " << 2 << endl;
		dfs(a, b, a + n - 1, b + n - 1, n);
		dfs(a, b + n, x, y, n);
		dfs(a + n, b, a + n, b + n - 1, n);
		dfs(a + n, b + n, a + n, b + n, n);
	}
	else if(x >= a + n && y < b + n) {
		cout << a + n - 1 << " " << b + n << " " << 3 << endl;
		dfs(a, b, a + n - 1, b + n - 1, n);
		dfs(a, b + n, a + n - 1, b + n, n);
		dfs(a + n, b, x, y, n);
		dfs(a + n, b + n, a + n, b + n, n);
	}
	else {
		cout << a + n - 1 << " " << b + n - 1 << " " << 4 << endl;
		dfs(a, b, a + n - 1, b + n - 1, n);
		dfs(a, b + n, a + n - 1, b + n, n);
		dfs(a + n, b, a + n, b + n - 1, n);
		dfs(a + n, b + n, x, y, n);
	}
}

int main() {
	int k, x, y; cin >> k >> x >> y;
	k = (1 << k);

	dfs(1, 1, x, y, k);

	return 0;
}
