#include<iostream>
#include<queue>
using namespace std;

const int N = 5e5 + 10;
int n, a, b;

priority_queue<int> hp;

int main() {
	cin >> n >> a >> b;
	for(int i=1; i<=n; ++i) {
		int x; cin >> x;
		hp.push(x);
	}
	
	int ret = 0, cnt = 0;
	while(hp.size()) {
		auto t = hp.top(); hp.pop();
		hp.push(t - b);
		cnt += a;
		++ret;
		if(cnt >= hp.top()) break;
	}
	cout << ret << endl;
	
	return 0;
}
