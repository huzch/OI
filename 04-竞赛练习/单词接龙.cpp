#include<iostream>
using namespace std;

typedef long long LL;
const int N = 30;
string a[N];
int cnt[N];
int n;
char head;
LL ret;

void dfs(string& s, LL len) {
	ret = max(ret, len);
	int sz = s.size();
	for(int i=1; i<=n; ++i) {
		if(cnt[i] == 2) continue;
		for(int j=sz-1; j>0; --j) {
			if(s.substr(j) == a[i].substr(0, sz - j)) {
				++cnt[i];
				dfs(a[i], len + a[i].size() - sz + j);
				--cnt[i];
			}
		}
	}
}

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];
	cin >> head;

	for(int i=1; i<=n; ++i) {
		if(a[i][0] == head) {
			++cnt[i];
			dfs(a[i], a[i].size());
			--cnt[i];
		}
	}

	cout << ret << endl;
	
	return 0;
}
