#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
int r[N], d[N], s[N], t[N];
LL f[N];
int n, m;

//是否满足完成[1,x]个订单
bool check(int x) {
	memset(f, 0, sizeof f);
	for(int i=1; i<=n; ++i) {
		f[i] += r[i], f[i + 1] -= r[i];
	}
	
	for(int i=1; i<=x; ++i) {
		int l = s[i], r = t[i];
		f[l] -= d[i], f[r + 1] += d[i];
	}
	
	for(int i=1; i<=n; ++i) {
		f[i] += f[i - 1];
		if(f[i] < 0) return false;
	}
	return true;
}

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> r[i];
	}
	for(int i=1; i<=m; ++i) {
		cin >> d[i] >> s[i] >> t[i];
	}
	
	//二分答案+差分 --- O(nlogn)
	int left = 1, right = m;
	while(left < right) {
		int mid = left + (right - left) / 2;
		if(!check(mid)) right = mid;
		else left = mid + 1;
	}
	
	if(check(left)) cout << 0 << endl;
	else {
		cout << -1 << endl;
		cout << left << endl;
	}
	
	return 0;
}
