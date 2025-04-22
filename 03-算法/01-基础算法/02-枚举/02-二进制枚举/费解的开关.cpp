#include <cstring>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 10;
int a[N], b[N];
int n = 5;

int calc(int x) {
	// lowbit
	int cnt = 0;
	while(x) {
		x &= x - 1;
		++cnt;
	}
	return cnt;
}

int main() {
	int t; cin >> t;
	while(t--) {
		memset(a, 0, sizeof a);

		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				char ch; cin >> ch;
				// 反转求解，求解全灭的步数
				if(ch == '0') a[i] |= 1 << j;
			}
		}

		// 二进制枚举，枚举第一行的选法
		int ret = INF;
		for(int st=0; st<(1<<n); ++st) {
			memcpy(b, a, sizeof a);

			int push = st;
			int cnt = 0;
			for(int i=0; i<n; ++i) {
				// 计算push的步数
				cnt += calc(push);
				// 处理当前行
				b[i] ^= push ^ (push << 1) ^ (push >> 1);
				b[i] &= (1 << n) - 1;
				// 处理下一行
				b[i + 1] ^= push;
				// 更新push
				push = b[i];
			}
			if(b[n - 1] == 0) ret = min(ret, cnt);
		}

		if(ret <= 6) cout << ret << endl;
		else cout << -1 << endl;
	}
	
	return 0;
}
