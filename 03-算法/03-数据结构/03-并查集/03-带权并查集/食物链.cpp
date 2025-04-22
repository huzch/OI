#include<iostream>
using namespace std;

const int N = 5e4 + 10;
int fa[N], d[N];
int n, k;

//d[i]：当前结点i与父结点fa[i]的距离
//d[i]==0：i与fa[i]为同类
//d[i]==1：i被fa[i]捕食
//d[i]==2：i捕食fa[i]

int find(int x) {
	if(fa[x] == x) return x;
	
	int t = find(fa[x]);
	d[x] += d[fa[x]]; //压缩路径时更新权值
	return fa[x] = t;
}

void un(int x, int y, int w) {
	int fx = find(x), fy = find(y);
	if(fx != fy) {
		fa[fx] = fy;
		d[fx] = d[y] - d[x] + w; //合并集合时更新权值
	}
}

int main() {
	cin >> n >> k;
	
	for(int i=1; i<=n; ++i) fa[i] = i;
	
	int ret = 0;
	while(k--) {
		int op, x, y; cin >> op >> x >> y;
		int fx = find(x), fy = find(y);
		//计算x与y之间的距离
		int t = ((d[y] - d[x]) % 3 + 3) % 3; // 0表示x==y，1表示x->y，2表示y->x
		
		if(x > n || y > n) ++ret;
		else if(op == 1) { // x==y
			if(fx == fy && t != 0) ++ret;
			else un(x, y, 0);
		}
		else { // x->y
			if(fx == fy && t != 1) ++ret;
			else un(x, y, 2);
		}
	}
	
	cout << ret << endl;
	
	return 0;
}
