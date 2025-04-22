#include<iostream>
using namespace std;

typedef long long LL;
//空间优化
LL a, b, c;
int n;

int main() {
	cin >> n;

	a = 1, b = 1, c = 2;
	for(int i=3; i<=n; ++i) {
		LL d = a + b + c;
		a = b, b = c, c = d;
	}
	
	if(n == 1) cout << 1 << endl;
	else cout << c << endl;

	return 0;
}



//#include<iostream>
//using namespace std;
//
//typedef long long LL;
//const int N = 70;
////f[i]:抵达第i个台阶，有多少种方案
//LL f[N];
//int n;
//
//int main() {
//	cin >> n;
//	
//	f[0] = 1, f[1] = 1, f[2] = 2;
//	for(int i=3; i<=n; ++i) {
//		f[i] = f[i - 1] + f[i - 2] + f[i - 3];
//	}
//	cout << f[n] << endl;
//	
//	return 0;
//}
