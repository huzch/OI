#include<iostream>
using namespace std;

const int N = 2e5 + 10;
int fa[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
	int n, T; cin >> n >> T;
	
	for(int i=1; i<=n; ++i) fa[i] = i;
	
	while(T--) {
		int z, x, y; cin >> z >> x >> y;
		int fx = find(x);
		int fy = find(y);
		if(z == 1) {
			fa[fx] = fy;
		}
		else if(z == 2) {
			if(fx == fy) cout << 'Y' << endl;
			else cout << 'N' << endl;
		}
	}
	
	return 0;
}
