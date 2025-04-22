#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> mp;
string s;
int x;

int main() {
	int n; cin >> n;
	while(n--) {
		int op; cin >> op;
		if(op == 1) {
			cin >> s >> x;
			mp[s] = x;
			cout << "OK" << endl;
		}
		else if(op == 2) {
			cin >> s;
			if(mp.count(s)) {
				cout << mp[s] << endl;
			}
			else {
				cout << "Not found" << endl;
			}
		}
		else if(op == 3) {
			cin >> s;
			if(mp.count(s)) {
				mp.erase(s);
				cout << "Deleted successfully" << endl;
			}
			else {
				cout << "Not found" << endl;
			}
		}
		else cout << mp.size() << endl;
	}
	return 0;
}
