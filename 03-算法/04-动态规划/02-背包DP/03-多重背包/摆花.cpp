#include<iostream>
using namespace std;

const int MOD = 1e6 + 7;
const int N = 110;
int a[N];
//f[i][j]:在前i种花中挑选，盆数为j时，所有的摆花方案
int f[N];
int n, m;

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i) cin >> a[i];
	
	f[0] = 1;
	for(int i=1; i<=n; ++i) {
		for(int j=m; j>=0; --j) {
			for(int k=1; k<=min(j, a[i]); ++k) {
				f[j] = f[j] + f[j - k];
				f[j] %= MOD;
			}
		}
	}
	cout << f[m] << endl;
	
	return 0;
}
