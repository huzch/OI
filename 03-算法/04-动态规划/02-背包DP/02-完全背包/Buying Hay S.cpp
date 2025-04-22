#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 110;
const int M = 5e4 + 10;
int v[N], w[N];
//f[i][j]:在前i个物品中，体积至少为j时，所得的最小价值
LL f[M];
int n, H;

int main() {
	cin >> n >> H;
	for(int i=1; i<=n; ++i) cin >> v[i] >> w[i];
	
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=0; j<=H; ++j) {
			f[j] = min(f[j], f[max(j - v[i], 0)] + w[i]);
		}
	}
	cout << f[H] << endl;
	
	return 0;
}
