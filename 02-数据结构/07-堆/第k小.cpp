#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> hp;
int n, m, k;

int main() {
	cin >> n >> m >> k;
	for(int i=1; i<=n; ++i) {
		int x; cin >> x;
		hp.push(x);
		if(hp.size() > k) hp.pop();
	}

	while(m--) {
		int op; cin >> op;
		if(op == 1) {
			int x; cin >> x;
			hp.push(x);
			if(hp.size() > k) hp.pop();
		}
		else if(op == 2) {
			if(hp.size() == k) {
				cout << hp.top() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}

	return 0;
}
