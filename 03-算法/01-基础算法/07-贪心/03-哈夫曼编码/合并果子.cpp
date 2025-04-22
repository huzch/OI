#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> hp;

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		int x; cin >> x;
		hp.push(x);
	}

	int ret = 0;
	while(hp.size() >= 2) {
		int x = hp.top(); hp.pop();
		int y = hp.top(); hp.pop();
		ret += x + y;
		hp.push(x + y);
	}
	cout << ret << endl;

	return 0;
}
