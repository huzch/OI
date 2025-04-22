#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int e[N], ne[N], pre[N], h, id;
int mp[N];

void insert_front(int p, int x) {
	e[++id] = x;
	mp[x] = id;

	ne[id] = p;
	pre[id] = pre[p];
	ne[pre[p]] = id;
	pre[p] = id;
}

void insert_back(int p, int x) {
	e[++id] = x;
	mp[x] = id;

	ne[id] = ne[p];
	pre[id] = p;
	pre[ne[p]] = id;
	ne[p] = id;
}

void erase(int p) {
	mp[e[p]] = 0;
	ne[pre[p]] = ne[p];
	if(ne[p]) pre[ne[p]] = pre[p];
}

int main() {
	int n; cin >> n;
	insert_back(0, 1);
	for(int i=2; i<=n; ++i) {
		int k, op;
		cin >> k >> op;
		int p = mp[k];
		if(op == 0) {
			insert_front(p, i);
		}
		else if(op == 1) {
			insert_back(p, i);
		}
	}

	int m; cin >> m;
	for(int i=1; i<=m; ++i) {
		int x; cin >> x;
		int p = mp[x];
		if(p) erase(p);
	}

	for(int i=ne[h]; i; i=ne[i]) {
		cout << e[i] << " ";
	}
	cout << endl;
	return 0;
}
