#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		unordered_set<int> mp;
		vector<int> a;
		for(int i=1; i<=n; ++i) {
			int x; cin >> x;
			auto kv = mp.insert(x);
			if(kv.second) a.push_back(x);
		}

		for(int x : a) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
