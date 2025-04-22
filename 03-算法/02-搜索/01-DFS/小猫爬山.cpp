#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;
int c[N], s[N];
int n, w;
int ret, cnt;

void dfs(int pos) {
	//最优性剪枝
	if(cnt >= ret) return;
	if(pos > n) {
		ret = cnt;
	}
	
	//先选已有车辆
	for(int i=1; i<=cnt; ++i) {
		//可行性剪枝
		if(c[pos] + s[i] > w) continue;
		s[i] += c[pos];
		dfs(pos + 1);
		s[i] -= c[pos];
	}
	//再选新开车辆
	s[++cnt] = c[pos];
	dfs(pos + 1);
	s[cnt--] = 0;
}

int main() {
	cin >> n >> w;
	for(int i=1; i<=n; ++i) {
		cin >> c[i];
	}
	
	//优先选取重量大的猫，以此前期更快获得结果，来进行最优性剪枝
	sort(c + 1, c + n + 1, [](int x, int y) {
		return x > y;
	});
	
	ret = n;
	dfs(1);
	cout << ret << endl;
	
	return 0;
}
