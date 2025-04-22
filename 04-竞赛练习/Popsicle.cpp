#include<iostream>
using namespace std;

int main() {
	int T; cin >> T;
	while(T--) {
		string n; cin >> n;
		int ret = 0, t = 10;
		for(auto& ch: n) {
			ret += ch - '0';
			t = min(t, ch - '0');
		}
		
		if(t == 0) ret += 9;
		else ret += 8;
		cout << ret << endl;
	}
	return 0;
}
