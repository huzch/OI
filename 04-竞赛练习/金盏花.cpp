#include<iostream>
using namespace std;

typedef long long LL;

int main() {
	LL y, z; cin >> y >> z;
	
	LL ret = 1e13;
	for(LL i=100000; i<=999999; ++i) {
		ret = min(ret, abs(i * 1000000 + y - z));
	}
	cout << ret << endl;
	
	return 0;
}
