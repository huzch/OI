#include <iostream>
using namespace std;

const int N = 23;
int h[N], e[N], ne[N], id;

int f(int x) {
	return (x % N + N) % N;
}

bool find(int x) {
	int idx = f(x);
	for(int i=h[idx]; i; i=ne[i]) {
		if(e[i] == x) return true;
	}
	return false;
}

void insert(int x) {
	if(find(x)) return;
	int idx = f(x);
	e[++id] = x;
	ne[id] = h[idx];
	h[idx] = id;
}

int main() {
	int n; cin >> n;
	while(n--) {
		int op, x; cin >> op >> x;
		if(op == 1) insert(x);
		else if(op == 2) {
			cout << find(x) << endl;
		}
	}
	return 0;
}
