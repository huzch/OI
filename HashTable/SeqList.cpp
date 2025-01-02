#include <cstring>
#include <iostream>
using namespace std;

const int N = 23; //质数
const int INF = 0x3f3f3f3f;
int h[N];

void init() {
	memset(h, INF, sizeof h);
}

int f(int x) {
	int id = (x % N + N) % N;
	while(h[id] != INF && h[id] != x) {
		id = (id + 1) % N;
	}
	return id;
}

void insert(int x) {
	int id = f(x);
	h[id] = x;
}

bool find(int x) {
	int id = f(x);
	return h[id] == x;
}

int main() {
	init();

	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		int op, x; cin >> op >> x;
		if(op == 1) {
			insert(x);
		}
		else if(op == 2) {
			cout << find(x) << endl;
		}
	}
	return 0;
}
