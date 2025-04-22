#include <cctype>
#include <iostream>
using namespace std;

int kinds;
int mp[256];

int main() {
	string s; cin >> s;
	int n = s.size();
	//创建窗口
	int ret = 0x3f3f3f3f;
	int left = 0, right = 0;
	while(right < n) {
		//进窗口
		mp[s[right]]++;
		if(islower(s[right]) && mp[s[right]] == 1) kinds++;
		//判断
		while(kinds == 26) {
			//更新结果
			ret = min(ret, right - left + 1);
			//出窗口
			mp[s[left]]--;
			if(islower(s[left]) && mp[s[left]] == 0) kinds--;
			left++;
		}
		right++;
	}
	cout << ret << endl;
	return 0;
}
