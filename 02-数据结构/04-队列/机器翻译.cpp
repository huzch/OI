#include <iostream>
using namespace std;

const int N = 1e3 + 10;
int q[N], h, t;
bool st[N];
int m, n, cnt;

int main() {
	cin >> m >> n;
	while(n--) {
		int x; cin >> x;
		if(!st[x]) {
			if(t - h == m) {
				++h;
				st[q[h]] = false;
			}
			q[++t] = x;
			st[x] = true;
			++cnt;
		}
	}
	cout << cnt << endl;
	return 0;
}
