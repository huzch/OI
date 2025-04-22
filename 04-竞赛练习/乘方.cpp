#include<iostream>
using namespace std;

typedef long long LL;

LL qpow(LL a, LL b) {
	LL ret = 1;
	while(b) {
		if(a > 1e9) return -1;
		if(b & 1) ret = ret * a;
		a = a * a;
		b >>= 1;
	}
 	return ret <= 1e9 ? ret : -1;
}

int main() {
	LL a, b; cin >> a >> b;
	
	cout << qpow(a, b) << endl;
	
	return 0;
}
