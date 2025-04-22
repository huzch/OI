#include<iostream>
using namespace std;

typedef long long LL;
const int N = 110;
LL f[N];

int main() {
	int n, m; cin >> n >> m;
	//利用差分进行区间操作
	for(int i=1; i<=m; ++i) {
		int l, r; cin >> l >> r;
		f[l] += 1, f[r + 1] -= 1;
	}
	
	//还原数组
	for(int i=1; i<=n; ++i) {
		f[i] += f[i - 1];
		if(f[i] == 0 || f[i] > 1) {
			cout << i << " " << f[i] << endl;
			return 0;
		}
	}
	cout << "OK" << endl;
	
	return 0;
}
