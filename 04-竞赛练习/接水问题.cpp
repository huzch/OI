#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

const int N = 1e4 + 10;
int a[N];

int main() {
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	
	priority_queue<int, vector<int>, greater<int>> hp;
	for(int i=1; i<=m; ++i) {
		hp.push(a[i]);
	}
	
	for(int i=m+1; i<=n; ++i) {
		int t = hp.top(); hp.pop();
		hp.push(t + a[i]);
	}
	
	int ret = 0;
	while(hp.size()) {
		int t = hp.top(); hp.pop();
		ret = max(ret, t);
	}
	cout << ret << endl;
	
	return 0;
}
