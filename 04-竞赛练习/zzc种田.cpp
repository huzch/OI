#include<iostream>
using namespace std;

typedef long long LL;

int main() {
	LL x, y; cin >> x >> y;

	LL ret = 0;
	while(x && y) {
		LL k = x / y;
		ret += 4 * k * y;
		x %= y;
		swap(x, y);
	}
	cout << ret << endl;

	return 0;
}

//int main() {
//	LL x, y; cin >> x >> y;
//	
//	LL ret = 0;
//	LL a = max(x, y), b = min(x, y);
//	while(a && b) {
//		LL c = a, d = b, k = a / b;
//		ret += 4 * k * d;
//		c -= k * d;
//		a = max(c, d);
//		b = min(c, d);
//	}
//	cout << ret << endl;
//	
//	return 0;
//}
