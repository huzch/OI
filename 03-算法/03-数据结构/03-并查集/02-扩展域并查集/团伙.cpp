#include<iostream>
using namespace std;

const int N = 1e3 + 10;
int fa[N * 2]; //扩展域并查集，两种关系
int n, m;

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void un(int x, int y) {
	//注意父节点必须为朋友域
	fa[find(y)] = find(x);
}

int main() {
	cin >> n >> m;
	
	//初始化并查集
	for(int i=1; i<=n*2; ++i) fa[i] = i;
	
	while(m--) {
		char opt; cin >> opt;
		int p, q; cin >> p >> q;
		int fp = find(p), fq = find(q);
		
		if(opt == 'F') {
			un(p, q);
		}
		else if(opt == 'E') {
			un(p, q + n);
			un(q, p + n);
		}
	}
	
	int ret = 0;
	for(int i=1; i<=n; ++i) {
		if(i == fa[i]) ++ret;
	}
	cout << ret << endl;
	
	return 0;
}
