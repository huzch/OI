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

//#include<iostream>
//#include<vector>
//#include<unordered_set>
//using namespace std;
//
//const int MOD = 1e9 + 7;
//vector<int> a, b;
//unordered_set<int> vis;
//int n, cnt;
//
//void dfs(int pos)
//{
//	if (pos == n)
//	{
//		if (vis.size() == n) cnt = (cnt + 1) % MOD;
//		return;
//	}
//
//	if (!vis.count(a[pos]))
//	{
//		vis.insert(a[pos]);
//		dfs(pos + 1);
//		vis.erase(a[pos]);
//	}
//
//	if (!vis.count(b[pos]))
//	{
//		vis.insert(b[pos]);
//		dfs(pos + 1);
//		vis.erase(b[pos]);
//	}
//}
//
//int main()
//{
//	cin >> n;
//	a.resize(n);
//	b.resize(n);
//	for (int i = 0; i < n; ++i) cin >> a[i];
//	for (int i = 0; i < n; ++i) cin >> b[i];
//	dfs(0);
//	cout << cnt << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
//int main() {
//	int n = 5;
//	int k = 10;
//	// cin >> n >> k;
//	int max = 0;
//	for (int i = 0; i < n; i++) {
//		if (i == n - 1) max = n;
//		if (pow(2, i) - 1 <= k && pow(2, i + 1) - 1 > k) {
//			max = i;
//
//			break;
//		}
//
//	}
//	cout << max;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int n;
//	string s;
//	cin >> n >> s;
//
//	int cnt = 0;
//	string t = "SYSU";
//	for (int i = 0; i < n; ++i)
//	{
//		int j = i % 4;
//		if (s[i] != t[j]) ++cnt;
//	}
//	cout << cnt << endl;
//	return 0;
//}