#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
int mp[N], kinds;

int main() {
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}

	//创建窗口
	int l = 0, r = INF;
	int left = 1, right = 1;
	while(right <= n) {
		//进窗口
		mp[a[right]]++;
		if(mp[a[right]] == 1) {
			kinds++;
		}
		//判断窗口是否合法
		while(kinds == m) {
			//更新结果
			if(right - left < r - l) {
				l = left;
				r = right;
			}
			//出窗口
			mp[a[left]]--;
			if(mp[a[left]] == 0) {
				kinds--;
			}
			left++;
		}
		right++;
	}

	cout << l << " " << r << endl;
	return 0;
}
