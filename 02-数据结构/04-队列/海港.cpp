#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;
queue<PII> q;
int cnt[N], kinds;
int n, t, k;

int main() {
	cin >> n;
	while(n--) {
		cin >> t >> k;
		while(k--) {
			int x; cin >> x;
			q.push({t, x});
			if(cnt[x]++ == 0) {
				++kinds;
			}
			while(q.size()) {
				PII front = q.front();
				if(front.first + 86400 <= t) {
					q.pop();
					if(--cnt[front.second] == 0) {
						--kinds;
					}
				}
				else break;
			}
		}
		cout << kinds << endl;
	}
	return 0;
}
