#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

const int N = 2e5 + 10;
bool ge[N];
int e[N], pre[N], ne[N];
int n;

struct node {
	int dx;
	int a, b;

	bool operator<(const node& n) const {
		if(dx != n.dx) return dx > n.dx;
		else if(a != n.a) return a > n.a;
		else return b > n.b;
	}
};

priority_queue<node> hp;
bool st[N];

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		char ch; cin >> ch;
		if(ch == 'B') ge[i] = true;
	}

	for(int i=1; i<=n; ++i) {
		int x; cin >> x;
		e[i] = x;
		pre[i] = i - 1;
		ne[i] = i + 1;
	}
	ne[n] = 0;

	for(int i=2; i<=n; ++i) {
		int dx = abs(e[i - 1] - e[i]);
		if(ge[i - 1] ^ ge[i]) {
			hp.push({dx, i - 1, i});
		}
	}

	vector<node> ret;
	while(hp.size()) {
		auto t = hp.top(); hp.pop();
		int dx = t.dx, a = t.a, b = t.b;
		if(!st[a] && !st[b]) {
			ret.push_back(t);
			st[a] = st[b] = true;

			int c = pre[a], d = ne[b];
			ne[c] = d;
			pre[d] = c;
			if(c && d && ge[c] ^ ge[d]) {
				int dy = abs(e[c] - e[d]);
				hp.push({dy, c, d});
			}
		}
	}

	cout << ret.size() << endl;
	for(auto t : ret) {
		cout << t.a << " " << t.b << endl;
	}

	return 0;
}
