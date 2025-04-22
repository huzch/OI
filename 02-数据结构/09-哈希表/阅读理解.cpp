#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

unordered_map<string, set<int>> mp;

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		int l; cin >> l;
		while(l--) {
			string s; cin >> s;
			mp[s].insert(i);
		}
	}

	int m; cin >> m;
	while(m--) {
		string t; cin >> t;
		if(mp.count(t)) {
			for(int x : mp[t]) {
				cout << x << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
