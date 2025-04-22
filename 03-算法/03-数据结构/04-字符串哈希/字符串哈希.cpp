#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e4 + 10;
const int P = 131;
ULL a[N];
int n;

ULL get_hash(string& s) {
	ULL ret = 0;
	for(int i=1; i<=s.size(); ++i) {
		ret = ret * P + s[i];
	}
	return ret;
}

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		string s; cin >> s;
		s = " " + s;
		a[i] = get_hash(s);
	}
	
	sort(a + 1, a + n + 1);
	
	int ret = 1;
	for(int i=2; i<=n; ++i) {
		if(a[i] != a[i - 1]) ++ret;
	}
	cout << ret << endl;
	
	return 0;
}
