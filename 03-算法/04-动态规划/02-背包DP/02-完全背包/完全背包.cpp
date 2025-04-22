#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e3 + 10;
int v[N], w[N];
//f[i][j]:前i种物品中，总体积不超过j时，所装的最大价值
//f[i][j]:前i种物品中，总体积必须为j时，所装的最大价值
int f[N];
int n, V;

int main() {
	cin >> n >> V;
	for(int i=1; i<=n; ++i) cin >> v[i] >> w[i];
	
	for(int i=1; i<=n; ++i) {
		for(int j=v[i]; j<=V; ++j) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	cout << f[V] << endl;
	
	memset(f, -0x3f, sizeof f);
	f[0] = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=v[i]; j<=V; ++j) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	if(f[V] < 0) cout << 0 << endl;
	else cout << f[V] << endl;
	
	return 0;
}
