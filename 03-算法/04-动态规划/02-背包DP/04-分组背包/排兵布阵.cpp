#include<iostream>
#include<algorithm>
using namespace std;

const int N = 110;
const int M = 2e4 + 10;
int a[N][N];
int f[M];
int s, n, m;

int main() {
	cin >> s >> n >> m;
	for(int i=1; i<=s; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> a[j][i]; //转置
			a[j][i] = a[j][i] * 2 + 1; //贪心
		}
	}
	
	for(int i=1; i<=n; ++i) {
		sort(a[i] + 1, a[i] + s + 1);
	}
	
	for(int i=1; i<=n; ++i) {
		for(int j=m; j>=0; --j) {
			for(int k=1; k<=s&&a[i][k]<=j; ++k) {
				f[j] = max(f[j], f[j - a[i][k]] + i * k);
			}
		}
	}
	cout << f[m] << endl;
	
	return 0;
}
