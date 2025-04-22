#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//const int N = 5e3 + 10;
//int a[N];
struct node {
	int x, y;
};
vector<node> a;
int n, s, h1, h2;

int main() {
	cin >> n >> s >> h1 >> h2;
	for(int i=1; i<=n; ++i) {
		int x, y; cin >> x >> y;
		if(h1 + h2 >= x) a.push_back({x, y});
	}
	
	sort(a.begin(), a.end(), [](node& n1, node& n2) {
		return n1.y < n2.y;
	});
	
	int ret = 0;
	for(auto& n: a) {
		if(s >= n.y) {
			++ret;
			s -= n.y;
		}
	}
	cout << ret << endl;
	
	return 0;
}
