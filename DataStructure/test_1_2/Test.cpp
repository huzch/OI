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












// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
//
// typedef long long LL;
// unordered_map<string, string> mp1;
// unordered_map<string, unordered_set<string>> mp2;
//
// int main() {
// 	int n; cin>> n;
// 	while(n--) {
// 		string s, t; cin >> s >> t;
// 		mp1[s] = t;
// 		string k = s.substr(0, 2);
// 		mp2[t].insert(k);
// 	}
//
// 	LL ret = 0;
// 	for(auto& [s, t] : mp1) {
// 		string k = s.substr(0, 2);
// 		if(k == t) continue; //只统计不同州的城市对
// 		if(mp2.count(k)) {
// 			ret += mp2[k].count(t);
// 		}
// 	}
// 	cout << ret / 2 << endl;
//
// 	return 0;
// }















// #include <iostream>
// #include <unordered_map>
// using namespace std;
//
// typedef long long LL;
// unordered_map<int, LL> mp;
//
// int main() {
// 	int n, c; cin >> n >> c;
// 	for(int i=1; i<=n; ++i) {
// 		int x; cin >> x;
// 		++mp[x];
// 	}
//
// 	LL ret = 0;
// 	for(auto& kv : mp) {
// 		int a = kv.first;
// 		LL cnt = kv.second;
// 		int b = a + c;
// 		if(mp.count(b)) ret += cnt * mp[b];
// 	}
// 	cout << ret << endl;
//
// 	return 0;
// }

















// #include <iostream>
// #include <set>
// #include <unordered_map>
// using namespace std;
//
// unordered_map<string, set<int>> mp;
//
// int main() {
// 	int n; cin >> n;
// 	for(int i=1; i<=n; ++i) {
// 		int l; cin >> l;
// 		while(l--) {
// 			string s; cin >> s;
// 			mp[s].insert(i);
// 		}
// 	}
//
// 	int m; cin >> m;
// 	while(m--) {
// 		string t; cin >> t;
// 		if(mp.count(t)) {
// 			for(int x : mp[t]) {
// 				cout << x << " ";
// 			}
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }











// #include <iostream>
// #include <unordered_set>
// #include <vector>
// using namespace std;
//
// int main() {
// 	int t; cin >> t;
// 	while(t--) {
// 		int n; cin >> n;
// 		unordered_set<int> mp;
// 		vector<int> a;
// 		for(int i=1; i<=n; ++i) {
// 			int x; cin >> x;
// 			auto kv = mp.insert(x);
// 			if(kv.second) a.push_back(x);
// 		}
//
// 		for(int x : a) {
// 			cout << x << " ";
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }














// #include <iostream>
// #include <unordered_map>
// using namespace std;
//
// unordered_map<string, int> mp;
// string s;
// int x;
//
// int main() {
// 	int n; cin >> n;
// 	while(n--) {
// 		int op; cin >> op;
// 		if(op == 1) {
// 			cin >> s >> x;
// 			mp[s] = x;
// 			cout << "OK" << endl;
// 		}
// 		else if(op == 2) {
// 			cin >> s;
// 			if(mp.count(s)) {
// 				cout << mp[s] << endl;
// 			}
// 			else {
// 				cout << "Not found" << endl;
// 			}
// 		}
// 		else if(op == 3) {
// 			cin >> s;
// 			if(mp.count(s)) {
// 				mp.erase(s);
// 				cout << "Deleted successfully" << endl;
// 			}
// 			else {
// 				cout << "Not found" << endl;
// 			}
// 		}
// 		else cout << mp.size() << endl;
// 	}
// 	return 0;
// }













// pair<bool, int> binary_search(vector<int> a, int t) {
// 	int cnt = 0;
// 	int l = 0, r = a.size() - 1;
// 	while(l < r) {
// 		int mid = l + (r - l + 1) / 2;
// 		if(a[mid] <= t) l = mid;
// 		else r = mid + 1;
// 		++cnt;
// 	}
//
// 	bool flag = false;
// 	if(a[l] == t) flag = true;
// 	return {flag, cnt};
// }












// #include <cstdlib>
// #include <iostream>
// #include <set>
// using namespace std;
//
// typedef long long LL;
// const LL INF = 1e10 + 10;
// set<LL> mp;
//
// int main() {
// 	int n; cin >> n;
// 	mp.insert(-INF); mp.insert(INF);
// 	while(n--) {
// 		int op, x; cin >> op >> x;
// 		if(op == 1) {
// 			if(mp.count(x)) {
// 				cout << "Already Exist" << endl;
// 			}
// 			else mp.insert(x);
// 		}
// 		else if(op == 2) {
// 			if(mp.size() == 2) {
// 				cout << "Empty" << endl;
// 			}
// 			else {
// 				auto it = mp.lower_bound(x);
// 				LL y = *it, z = *--it;
// 				if(abs(x - y) < abs(x - z)) {
// 					mp.erase(y);
// 					cout << y << endl;
// 				}
// 				else {
// 					mp.erase(z);
// 					cout << z << endl;
// 				}
// 			}
// 		}
// 	}
// 	return 0;
// }
//














// #include <cstdlib>
// #include <iostream>
// #include <set>
// #include <algorithm>
// using namespace std;
//
// typedef long long LL;
// const int INF = 1e7 + 10;
// set<int> mp;
// LL ret;
// int n;
//
// int main() {
// 	cin >> n;
// 	cin >> ret; mp.insert(ret);
// 	mp.insert(-INF); mp.insert(INF);
// 	for(int i=2; i<=n; ++i) {
// 		int x; cin >> x;
// 		auto it = mp.lower_bound(x);
// 		int y = *it, z = *--it;
// 		ret += min(abs(x - y), abs(x - z));
// 		mp.insert(x);
// 	}
// 	cout << ret << endl;
// 	return 0;
// }





















// #include <cstdio>
// #include <iostream>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
//
// typedef long long LL;
// unordered_map<string, int> mp;
// unordered_set<char> s = {',', '.', '!', '?', ' ', '\n'};
// int n, p;
// char ch;
//
// int main() {
// 	cin >> n >> p;
// 	for(int i=1; i<=n; ++i) {
// 		string s; int x;
// 		cin >> s >> x;
// 		mp[s] = x;
// 	}
//
// 	LL ret = 0;
// 	string t = "";
// 	while((ch = getchar()) != EOF) {
// 		if(s.count(ch)) {
// 			ret = (ret + mp[t]) % p;
// 			t = "";
// 		}
// 		else t += ch;
// 	}
// 	cout << ret << endl;
//
// 	return 0;
// }




// #include <cstdio>
// #include <iostream>
// #include <map>
// #include <set>
// using namespace std;
//
// typedef long long LL;
// map<string, int> mp;
// set<char> s = {',', '.', '!', '?', ' ', '\n'};
// int n, p;
// char ch;
//
// int main() {
// 	cin >> n >> p;
// 	for(int i=1; i<=n; ++i) {
// 		string s; int x;
// 		cin >> s >> x;
// 		mp[s] = x;
// 	}
//
// 	LL ret = 0;
// 	string t = "";
// 	while((ch = getchar()) != EOF) {
// 		if(s.count(ch)) {
// 			ret = (ret + mp[t]) % p;
// 			t = "";
// 		}
// 		else t += ch;
// 	}
// 	cout << ret << endl;
//
// 	return 0;
// }
