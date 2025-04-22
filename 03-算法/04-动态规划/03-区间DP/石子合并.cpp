//处理环形问题：复写
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;
const int N = 110 * 2;
int s[N];
LL f[N][N];
LL g[N][N];
int n;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> s[i];
		s[i + n] = s[i];
	}
	
	for(int i=1; i<=2*n; ++i) {
		s[i] += s[i - 1];
	}
	
	memset(f, 0x3f, sizeof f);
	memset(g, -0x3f, sizeof g);
	for(int i=0; i<=2*n; ++i) f[i][i] = g[i][i] = 0;
	for(int len=2; len<=n; ++len) {
		for(int i=1; i+len-1<=2*n; ++i) {
			int j = i + len - 1, sum = s[j] - s[i - 1];
			for(int k=i; k<j; ++k) {
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sum);
				g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j] + sum);
			}
		}
	}
	
	LL ret1 = INF, ret2 = -INF;
	for(int i=1; i<=n; ++i) {
		ret1 = min(ret1, f[i][i+n-1]);
		ret2 = max(ret2, g[i][i+n-1]);
	}
	cout << ret1 << endl << ret2 << endl;
	
	return 0;
}
