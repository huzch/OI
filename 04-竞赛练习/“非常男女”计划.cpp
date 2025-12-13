#include<iostream>
#include<unordered_map>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int f[N];
unordered_map<int, int> mp;

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		if(a[i] == 0) a[i] = -1; //技巧：配对问题正负抵消
	}
	
	mp[0] = 0; //重要初始化，否则一段正负相消和为0的区间统计不到
	for(int i=1; i<=n; ++i) {
		f[i] = f[i - 1] + a[i];
		//仅存储最先出现的前缀和，以保证最大长度
		if(!mp.count(f[i])) mp[f[i]] = i;
	}
	
	int ret = 0;
	for(int i=1; i<=n; ++i) {
		if(mp.count(f[i])) ret = max(ret, i - mp[f[i]]);
	}
	cout << ret << endl;
	
	return 0;
}
