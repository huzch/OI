//贪心错误，只能动态规划
#include<iostream>
using namespace std;

typedef long long LL;
const int N = 2e3 + 10;
int v[N];
LL f[N][N];
int n;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> v[i];
		f[i][i] = v[i] * n;
	}
	
	for(int len=2; len<=n; ++len) {
		for(int i=1; i+len-1<=n; ++i) {
			int j = i + len - 1, a = n - len + 1;
			f[i][j] = max(f[i + 1][j] + v[i] * a, f[i][j - 1] + v[j] * a);
		}
	}
	cout << f[1][n] << endl;
	
	return 0;
}
