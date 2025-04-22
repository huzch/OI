#include<iostream>
using namespace std;

typedef long long LL;
const int N = 110 * 2;
int a[N];
LL f[N][N];
int n;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	
	for(int len=2; len<=n; ++len) {
		for(int i=1; i+len-1<2*n; ++i) {
			int j = i + len - 1;
			for(int k=i; k<j; ++k) {
				f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
			}
		}
	}
	
	LL ret = 0;
	for(int i=1; i<=n; ++i) {
		ret = max(ret, f[i][i + n - 1]);
	}
	cout << ret << endl;
	
	return 0;
}
