#include<iostream>
using namespace std;

const int N = 1e2 + 10;
const int M = 1e3 + 10;
int a[N], b[N], c[N];
int f[M][M];
int n, m, x;

int main() {
	cin >> n >> m >> x;
	for(int i=1; i<=n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	
	for(int i=1; i<=n; ++i) {
		for(int j=m; j>=b[i]; --j) {
			for(int k=x; k>=c[i]; --k) {
				f[j][k] = max(f[j][k], f[j - b[i]][k - c[i]] + a[i]);
			}
		}
	}
	cout << f[m][x] << endl;
	
	return 0;
}
