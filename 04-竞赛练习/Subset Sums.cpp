//dp --- 01背包
//f[i][j]:[1,i]中，总和为j时，所有的方案数
#include<iostream>
using namespace std;

typedef long long LL;
const int N = 810;
LL f[N];

int main() {
	int n; cin >> n;
	int sum = (1 + n) * n / 2;
	if(sum & 1) {
		cout << 0 << endl;
		return 0;
	}
	
	f[0] = 1;
	int t = sum / 2;
	for(int i=1; i<=n; ++i) {
		for(int j=t; j>=i; --j) {
			f[j] = f[j] + f[j - i];
		}
	}
	cout << f[t] / 2 << endl;
	
	return 0;
}







//dfs --- 部分超时
//#include<iostream>
//using namespace std;
//
//int n, t;
//int sum, ret;
//
//void dfs(int x) {
//	if(x > n) {
//		if(sum == t) ++ret;
//		return;
//	}
//	
//	dfs(x + 1);
//	
//	sum += x;
//	dfs(x + 1);
//	sum -= x;
//}
//
//int main() {
//	cin >> n;
//	t = (1 + n) * n / 4;
//	
//	dfs(1);
//	cout << ret / 2 << endl;
//	
//	return 0;
//}
