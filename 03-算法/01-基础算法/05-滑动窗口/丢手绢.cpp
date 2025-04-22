#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];
typedef long long LL;
LL sum;

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	//创建窗口
	int left = 1, right = 1;
	LL ret = 0, k = 0;
	while(right <= n) {
		//进窗口
		k += a[right];
		//判断窗口合法性
		while(2 * k > sum) {
			//更新结果
			ret = max(ret, sum - k);
			//出窗口
			k -= a[left];
			left++;
		}
		//更新结果
		ret = max(ret, k);
		right++;
	}

	cout << ret << endl;
	return 0;
}
