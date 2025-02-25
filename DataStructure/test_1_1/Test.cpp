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


















// #include <iostream>
// #include <queue>
// using namespace std;
//
// typedef long long LL;
// const int N = 1e5 + 10;
// int a[N], b[N];
// int n;
//
// struct node {
// 	LL f;
// 	int i;
// 	int j;
//
// 	bool operator<(const node& n) const {
// 		return f > n.f;
// 	}
// };
//
// priority_queue<node> hp;
//
// int main() {
// 	cin >> n;
// 	for(int i=1; i<=n; ++i) cin >> a[i];
// 	for(int i=1; i<=n; ++i) cin >> b[i];
// 	for(int i=1; i<=n; ++i) {
// 		hp.push({a[i] + b[1], i, 1});
// 	}
//
// 	while(n--) {
// 		auto t = hp.top(); hp.pop();
// 		cout << t.f << " ";
// 		int i = t.i, j = t.j;
// 		hp.push({a[i] + b[j + 1], i, j + 1});
// 	}
// 	return 0;
// }
















// #include <iostream>
// #include <queue>
// using namespace std;
//
// const int N = 1e4 + 10;
// int a[N], b[N], c[N];
// int n, m;
//
// struct node {
// 	int f; //函数值
// 	int i; //函数编号
// 	int x; //代入值
//
// 	bool operator<(const node& n) const {
// 		return f > n.f;
// 	}
// };
//
// priority_queue<node> hp;
//
// int calc(int i, int x) {
// 	int f = a[i] * x * x + b[i] * x + c[i];
// 	return f;
// }
//
// int main() {
// 	cin >> n >> m;
// 	for(int i=1; i<=n; ++i) {
// 		cin >> a[i] >> b[i] >> c[i];
// 		hp.push({calc(i, 1), i, 1});
// 	}
//
// 	while(m--) {
// 		auto n = hp.top(); hp.pop();
// 		cout << n.f << " ";
// 		hp.push({calc(n.i, n.x + 1), n.i, n.x + 1});
// 	}
//
// 	return 0;
// }














// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;
//
// priority_queue<int> hp;
// vector<int> a;
// int n, k;
//
// int main() {
// 	cin >> n >> k;
// 	long long sum = 0;
// 	for(int i=1; i<=n; ++i) {
// 		int x; cin >> x;
// 		if(x % 2 == 0) hp.push(x);
// 		else sum += x;
// 	}
//
// 	while(k-- && hp.size()) {
// 		int top = hp.top(); hp.pop();
// 		int x = top / 2;
// 		if(x % 2 == 0) hp.push(x);
// 		else sum += x;
// 	}
//
// 	while(hp.size()) {
// 		sum += hp.top(); hp.pop();
// 	}
// 	cout << sum << endl;
//
// 	return 0;
// }















// #include <iostream>
// #include <queue>
// using namespace std;
//
// priority_queue<int> hp;
// int n, m, k;
//
// int main() {
// 	cin >> n >> m >> k;
// 	for(int i=1; i<=n; ++i) {
// 		int x; cin >> x;
// 		hp.push(x);
// 		if(hp.size() > k) hp.pop();
// 	}
//
// 	while(m--) {
// 		int op; cin >> op;
// 		if(op == 1) {
// 			int x; cin >> x;
// 			hp.push(x);
// 			if(hp.size() > k) hp.pop();
// 		}
// 		else if(op == 2) {
// 			if(hp.size() == k) {
// 				cout << hp.top() << endl;
// 			}
// 			else {
// 				cout << -1 << endl;
// 			}
// 		}
// 	}
//
// 	return 0;
// }












// #include <iostream>
// #include <utility>
// using namespace std;
//
// const int N = 1e6 + 10;
// int hp[N], n;
//
// void up(int child) {
// 	int parent = child / 2;
// 	while(parent >= 1) {
// 		if(hp[child] < hp[parent]) {
// 			swap(hp[child], hp[parent]);
// 			child = parent;
// 			parent = child / 2;
// 		}
// 		else break;
// 	}
// }
//
// void down(int parent) {
// 	int child = parent * 2;
// 	while(child <= n) {
// 		if(child + 1 <= n && hp[child + 1] < hp[child]) {
// 			++child;
// 		}
//
// 		if(hp[child] < hp[parent]) {
// 			swap(hp[child], hp[parent]);
// 			parent = child;
// 			child = parent * 2;
// 		}
// 		else break;
// 	}
// }
//
// int main() {
// 	int t; cin >> t;
// 	while(t--) {
// 		int op; cin >> op;
// 		if(op == 1) {
// 			int x; cin >> x;
// 			hp[++n] = x;
// 			up(n);
// 		}
// 		else if(op == 2) {
// 			cout << hp[1] << endl;
// 		}
// 		else if(op == 3) {
// 			swap(hp[1], hp[n--]);
// 			down(1);
// 		}
// 	}
// 	return 0;
// }
