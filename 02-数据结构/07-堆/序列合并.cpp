#include <iostream>
#include <queue>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int a[N], b[N];
int n;

struct node {
	LL f;
	int i;
	int j;

	bool operator<(const node& n) const {
		return f > n.f;
	}
};

priority_queue<node> hp;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];
	for(int i=1; i<=n; ++i) cin >> b[i];
	for(int i=1; i<=n; ++i) {
		hp.push({a[i] + b[1], i, 1});
	}

	while(n--) {
		auto t = hp.top(); hp.pop();
		cout << t.f << " ";
		int i = t.i, j = t.j;
		hp.push({a[i] + b[j + 1], i, j + 1});
	}
	return 0;
}
