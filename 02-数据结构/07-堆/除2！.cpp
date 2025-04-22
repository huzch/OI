#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> hp;
vector<int> a;
int n, k;

int main() {
	cin >> n >> k;
	long long sum = 0;
	for(int i=1; i<=n; ++i) {
		int x; cin >> x;
		if(x % 2 == 0) hp.push(x);
		else sum += x;
	}

	while(k-- && hp.size()) {
		int top = hp.top(); hp.pop();
		int x = top / 2;
		if(x % 2 == 0) hp.push(x);
		else sum += x;
	}

	while(hp.size()) {
		sum += hp.top(); hp.pop();
	}
	cout << sum << endl;

	return 0;
}
