#include <iostream>
#include <queue>
using namespace std;

const int N = 1e4 + 10;
int a[N], b[N], c[N];
int n, m;

struct node {
	int f; //函数值
	int i; //函数编号
	int x; //代入值
	
	bool operator<(const node& n) const {
		return f > n.f;
	}
};

priority_queue<node> hp;

int calc(int i, int x) {
	int f = a[i] * x * x + b[i] * x + c[i];
	return f;
}

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		hp.push({calc(i, 1), i, 1});
	}

	while(m--) {
		auto n = hp.top(); hp.pop();
		cout << n.f << " ";
		hp.push({calc(n.i, n.x + 1), n.i, n.x + 1});
	}

	return 0;
}
