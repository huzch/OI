#include<iostream>
using namespace std;

typedef long long LL;
const int N = 1e3 + 10;
LL x[N], y[N], z[N];
LL n, h, r;

int fa[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void un(int x, int y) {
	fa[find(x)] = find(y);
}

bool check(int i, int j) {
	LL d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]);
	return d <= 4 * r * r;
}

int main() {
	int T; cin >> T;
	while(T--) {
		cin >> n >> h >> r;
		
		for(int i=0; i<=n+1; ++i) {
			fa[i] = i;
		}
		
		//0号空洞和n+1号空洞代表下表面和上表面
		for(int i=1; i<=n; ++i) {
			cin >> x[i] >> y[i] >> z[i];
			//判断与下表面连通
			if(z[i] <= r) un(0, i);
			//判断与上表面连通
			if(z[i] + r >= h) un(i, n + 1);
			//判断其余空洞连通
			for(int j=1; j<i; ++j) {
				if(check(i, j)) un(i, j);
			}
		}
		
		if(find(0) == find(n + 1)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
