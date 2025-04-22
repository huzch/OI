#include <cstring>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 20;
int a[N], t[N];
int n;

int check(int x, int y) {
	int cnt = 0;
	for (int i=0; i<n; ++i) {
		if(((x >> i) & 1) == 0 && ((y >> i) & 1) == 1) ++cnt;
		if(((x >> i) & 1) == 1 && ((y >> i) & 1) == 0) return -1;
	}
	return cnt;
}

//返回改变元素的最小个数
int solve() {
	int ret = INF;
	//二进制枚举第一行的改变，即最终状态
	for(int st=0; st<(1<<n); ++st) {
		//每轮枚举记得先拷贝
		memcpy(t, a, sizeof a);

		int change = st;
		int cnt = 0;
		bool flag = true;
		//确定第一行状态后，后续每行状态可依次推出
		for (int i=1; i<=n; ++i) {
			//检测当前状态是否合法
			int c = check(t[i], change);
			if(c == -1) {
				flag = false;
				break;
			}
			//统计当前行改变的个数
			cnt += c;
			//改变当前行的状态
			t[i] = change;
			//推导下一行的状态
			change = t[i - 1] ^ (t[i] << 1) ^ (t[i] >> 1);
			//修正溢出错误
			change &= (1 << n) - 1;
		}
		//选取每轮枚举的最小值
		if(flag) ret = min(ret, cnt);
	}
	//若无解则返回-1
	return ret == INF ? -1 : ret;
}

int main() {
	int T; cin >> T;
	for(int k=1; k<=T; ++k) {
		//多组数据记得先清空
		memset(a, 0, sizeof a);
		cin >> n;
		//空出a[0]，处理边界
		for(int i=1; i<=n; ++i) {
			for(int j=0; j<n; ++j) {
				int x; cin >> x;
				if(x) a[i] |= (1 << j);
			}
		}
		printf("Case %d: %d\n", k, solve());
	}
	return 0;
}
