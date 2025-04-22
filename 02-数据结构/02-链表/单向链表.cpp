#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;
int e[N], ne[N], h, id;
int mp[M];
int q, op, x, y;

void insert(int p, int y) {
	e[++id] = y;
	mp[y] = id;
	ne[id] = ne[p];
	ne[p] = id;
}

void erase(int p) {
	if(ne[p]) {
		ne[p] = ne[ne[p]];
	}
}

int main() {
	cin >> q;
	insert(0, 1);
	while(q--) {
		cin >> op >> x;
		int p = mp[x];
		if(op == 1) {
			cin >> y;
			insert(p, y);
		}
		else if(op == 2) {
			cout << e[ne[p]] << endl;
		}
		else if(op == 3) {
			erase(p);
		}
	}
	return 0;
}
