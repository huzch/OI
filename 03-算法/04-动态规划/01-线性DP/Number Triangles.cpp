#include<iostream>
using namespace std;

typedef long long LL;
const int N = 1e3 + 10;
//空间优化
LL f[N];
int n;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		for(int j=i; j>=1; --j) {
			int x; cin >> x;
			f[j] = max(f[j - 1], f[j]) + x;
		}
	}

	LL ret = 0;
	for(int j=1; j<=n; ++j) {
		ret = max(ret, f[j]);
	}
	cout << ret << endl;

	return 0;
}




//#include<iostream>
//using namespace std;
//
//typedef long long LL;
//const int N = 1e3 + 10;
////f[i][j]:抵达(i, j)位置时，所得的最大权值
//LL f[N][N];
//int n;
//
//int main() {
//	cin >> n;
//	for(int i=1; i<=n; ++i) {
//		for(int j=1; j<=i; ++j) {
//			cin >> f[i][j];
//          //若权值存在负数，dp表要初始化为-INF
//			f[i][j] += max(f[i - 1][j - 1], f[i - 1][j]);
//		}
//	}
//	
//	LL ret = 0;
//	for(int j=1; j<=n; ++j) {
//		ret = max(ret, f[n][j]);
//	}
//	cout << ret << endl;
//	
//	return 0;
//}
