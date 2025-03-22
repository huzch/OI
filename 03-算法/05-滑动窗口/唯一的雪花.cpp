#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 1e6 + 10;
int a[N];

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		for(int i=1; i<=n; ++i) {
			cin >> a[i];
		}

		//创建窗口
		int ret = 0;
		int left = 1, right = 1;
		unordered_map<int, int> mp;
		while(right <= n) {
			//进窗口
			mp[a[right]]++;
			//判断窗口是否合法
			while(mp[a[right]] > 1) {
				//出窗口
				mp[a[left]]--;
				left++;
			}
			//更新结果
			right++;
			ret = max(ret, right - left);
		}

		cout << ret << endl;
	}
	return 0;
}
