#include<iostream>
using namespace std;

typedef long long LL;
const int N = 1e4 + 10;
const int M = 1e7 + 10;
int v[N], w[N];
LL f[M];
int t, n;

int main() {
	cin >> t >> n;
	for(int i=1; i<=n; ++i) cin >> v[i] >> w[i];
	
	for(int i=1; i<=n; ++i) {
		for(int j=v[i]; j<=t; ++j) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	cout << f[t] << endl;
	
	return 0;
}
