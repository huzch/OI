#include<iostream>
using namespace std;

const int N = 5e4 + 10;
int fa[N * 3]; //同类，捕食，被捕食三种关系
int n, k;

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void un(int x, int y) {
	fa[find(y)] = find(x);
}

int main() {
	cin >> n >> k;
	
	for(int i=1; i<=n*3; ++i) fa[i] = i;

	int ret = 0;
	while(k--) {
		int op, x, y;
		cin >> op >> x >> y;
		if(x > n || y > n || (op == 2 && x == y)) {
			++ret;
			continue;
		}

		if(op == 1) {
			// y->x || x->y
			if(find(x) == find(y + n) || find(x) == find(y + n + n)) {
				++ret;
				continue;
			}
			un(x, y);
			un(x + n, y + n);
			un(x + n + n, y + n + n);
		}
		else {
			// x==y || y->x
			if(find(x) == find(y) || find(x) == find(y + n)) {
				++ret;
				continue;
			}
			un(x, y + n + n);
			un(x + n, y);
			un(x + n + n, y + n);
		}
	}
	
	cout << ret << endl;
	
	return 0;
}
