#include <iostream>
using namespace std;

const int N = 110;
int ne[N];
int n, m;

int main() {
	cin >> n >> m;
	for(int i=1; i<n; ++i) {
		ne[i] = i + 1;
	}
	ne[n] = 1;

	int t = n;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<m; ++j) {
			t = ne[t];
		}
		cout << ne[t] << " ";

		ne[t] = ne[ne[t]];
	}
	return 0;
}
