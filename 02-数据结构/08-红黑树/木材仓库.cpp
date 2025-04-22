#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;

typedef long long LL;
const LL INF = 1e10 + 10;
set<LL> mp;

int main() {
	int n; cin >> n;
	mp.insert(-INF); mp.insert(INF);
	while(n--) {
		int op, x; cin >> op >> x;
		if(op == 1) {
			if(mp.count(x)) {
				cout << "Already Exist" << endl;
			}
			else mp.insert(x);
		}
		else if(op == 2) {
			if(mp.size() == 2) {
				cout << "Empty" << endl;
			}
			else {
				auto it = mp.lower_bound(x);
				LL y = *it, z = *--it;
				if(abs(x - y) < abs(x - z)) {
					mp.erase(y);
					cout << y << endl;
				}
				else {
					mp.erase(z);
					cout << z << endl;
				}
			}
		}
	}
	return 0;
}
