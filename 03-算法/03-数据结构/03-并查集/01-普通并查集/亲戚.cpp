#include<iostream>
using namespace std;

const int N = 5e3 + 10;
int fa[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
	int n, m, p; cin >> n >> m >> p;
	for(int i=1; i<=n; ++i) fa[i] = i;
	for(int i=1; i<=m; ++i) {
		int x, y; cin >> x >> y;
		int fx = find(x), fy = find(y);
		fa[fx] = fy;
	}
	
	while(p--) {
		int x, y; cin >> x >> y;
		int fx = find(x), fy = find(y);
		if(fx == fy) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
