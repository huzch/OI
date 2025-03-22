#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;
unordered_map<int, LL> mp;

int main() {
	int n, c; cin >> n >> c;
	for(int i=1; i<=n; ++i) {
		int x; cin >> x;
		++mp[x];
	}

	LL ret = 0;
	for(auto& kv : mp) {
		int a = kv.first;
		LL cnt = kv.second;
		int b = a + c;
		if(mp.count(b)) ret += cnt * mp[b];
	}
	cout << ret << endl;

	return 0;
}
