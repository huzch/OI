#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1);
	v[1] = 1;
	for (int i = 2; i <= n; i++) {
		v[i] = v[i - 1] * i;
	}
	int ans = v[n];
	for (int i = 1; i <= n; i++) {
		int temp = i % 2 == 1 ? -1 : 1;
		ans += v[n] * temp / v[i];
	}
	int res = v[n - k];
	for (int i = 1; i <= n - k; i++) {
		int temp = i % 2 == 1 ? -1 : 1;
		res += v[n - k] * temp / v[i];
	}

	cout << ans - res - 1 << endl;
}