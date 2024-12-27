#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int N = 30;
vector<int> p[N];
int n, a, b;

pair<int, int> find(int e) {
	for(int i=0; i<n; ++i) {
		for(int j=0; j<p[i].size(); ++j) {
			if(p[i][j] == e) return {i, j};
		}
	}
	return {-1, -1};
}

void reset(int x, int y) {
	for(int j=y+1; j<p[x].size(); ++j) {
		int e = p[x][j];
		p[e].push_back(e);
	}
	p[x].resize(y + 1);
}

void set(int x1, int y1, int x2) {
	for(int j=y1; j<p[x1].size(); ++j) {
		int e = p[x1][j];
		p[x2].push_back(e);
	}
	p[x1].resize(y1);
}

int main() {
	cin >> n;
	for(int i=0; i<n; ++i) {
		p[i].push_back(i);
	}

	string op1, op2;
	while(cin >> op1 >> a >> op2 >> b) {
		auto [x1, y1] = find(a);
		auto [x2, y2] = find(b);
		if(x1 == x2) continue;
		if(op1 == "move") reset(x1, y1);
		if(op2 == "onto") reset(x2, y2);
		set(x1, y1, x2);
	}

	for(int i=0; i<n; ++i) {
		cout << i << ":";
		for(int e : p[i]) {
			cout << " " << e;
		}
		cout << endl;
	}
	return 0;
}










// #include <iostream>
// #include <vector>
// using namespace std;
//
// int n, q;
// int i, j, k;
//
// int main()
// {
// 	cin >> n >> q;
// 	vector<vector<int>> aa(n + 1);
//
// 	while(q--)
// 	{
// 		int op; cin >> op;
// 		if(op == 1)
// 		{
// 			cin >> i >> j >> k;
// 			if(aa[i].size() <= j)
// 			{
// 				aa[i].resize(j + 1);
// 			}
// 			aa[i][j] = k;
// 		}
// 		else if(op == 2)
// 		{
// 			cin >> i >> j;
// 			cout << aa[i][j] << endl;
// 		}
// 	}
// 	return 0;
// }













// #include <iostream>
// #include <vector>
// using namespace std;
//
// int main()
// {
// 	int n, m;
// 	cin >> n >> m;
// 	vector<int> a(n + 1);
// 	for(int i=1; i<=n; ++i)
// 	{
// 		cin >> a[i];
// 	}
//
// 	while(m--)
// 	{
// 		int p;
// 		cin >> p;
// 		cout << a[p] << endl;
// 	}
// 	return 0;
// }
