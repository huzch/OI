#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int n; cin >> n;

	int ret = 0;
	unordered_map<string, int> mp;
	while(n--) {
		string s, t; cin >> s >> t;
		s = s.substr(0, 2);
		if(s == t) continue; //只统计不同州的城市对
		ret += mp[t + s];
		++mp[s + t];
	}
	cout << ret << endl;

	return 0;
}
