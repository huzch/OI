#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;
	if(n & 1) cout << -1 << endl;
	else {
		for(int i=31; i>=1; --i) {
			if((n >> i) & 1) {
				cout << (1 << i) << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
