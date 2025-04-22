#include<iostream>
using namespace std;

typedef long long LL;
const int N = 110;
const int M = 1e3 + 10;
int t[N], w[N];
LL f[M];
int T, n;

int main() {
	cin >> T >> n;
	for(int i=1; i<=n; ++i) {
		cin >> t[i] >> w[i];
	}
	
	for(int i=1; i<=n; ++i) {
		for(int j=T; j>=t[i]; --j) {
			f[j] = max(f[j], f[j - t[i]] + w[i]);
		}
	}
	cout << f[T] << endl;
	
	return 0;
}
