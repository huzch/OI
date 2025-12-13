#include<iostream>
using namespace std;

const int N = 3e4 + 10;
int fa[N], d[N], cnt[N];
int n = 3e4;
int T;

//d:当前结点与父结点的距离
//cnt:以当前结点为根，集合中的元素个数

int find(int x) {
	if(fa[x] == x) return x;
	int root = find(fa[x]);
	d[x] += d[fa[x]];
	return fa[x] = root;
}

void un(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx != fy) {
    	fa[fx] = fy;
    	d[fx] = cnt[fy];
    	cnt[fy] += cnt[fx];
	}
}

int main() {
	cin >> T;
	for(int i=1; i<=n; ++i) {
		fa[i] = i;
		cnt[i] = 1;
	}
	
	while(T--) {
		char op; int x, y;
		cin >> op >> x >> y;
		if(op == 'M') un(x, y);
		else {
			int fx = find(x), fy = find(y);
			if(fx != fy) cout << -1 << endl;
			else cout << abs(d[x] - d[y]) - 1 << endl;
		}
	}
	
	return 0;
}
