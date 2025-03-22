#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long LL;
unordered_map<string, int> mp;
unordered_set<char> s = {',', '.', '!', '?', ' ', '\n'};
int n, p;
char ch;

int main() {
	cin >> n >> p;
	for(int i=1; i<=n; ++i) {
		string s; int x;
		cin >> s >> x;
		mp[s] = x;
	}

	LL ret = 0;
	string t = "";
	while((ch = getchar()) != EOF) {
		if(s.count(ch)) {
			ret = (ret + mp[t]) % p;
			t = "";
		}
		else t += ch;
	}
	cout << ret << endl;

	return 0;
}
