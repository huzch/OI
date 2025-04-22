#include<iostream>
using namespace std;

const int N = 1e4 + 10;
const int M = 1e3 + 10;
int t[N], c[N], p[N];
int f[M];
int h1, m1, h2, m2, T, n;
char ch;

int main() {
	cin >> h1 >> ch >> m1 >> h2 >> ch >> m2 >> n;
	T = h2 * 60 + m2 - h1 * 60 - m1;
	for(int i=1; i<=n; ++i) {
		cin >> t[i] >> c[i] >> p[i];
	}

	for(int i=1; i<=n; ++i) {
		if(p[i] == 0) {
			for(int j=t[i]; j<=T; ++j) {
				f[j] = max(f[j], f[j - t[i]] + c[i]);
			}
		}
		else {
			for(int j=T; j>=0; --j) {
					for(int k=1; k<=p[i]&&k*t[i]<=j; ++k) {
					f[j] = max(f[j], f[j - k * t[i]] + k * c[i]);
				}
			}
		}
	}
	cout << f[T] << endl;
	
	return 0;
}
