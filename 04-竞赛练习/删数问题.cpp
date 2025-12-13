#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string a; cin >> a;
	int n = a.size();
	int k; cin >> k;
	//特殊情况
	if(n <= k) {
		cout << 0 << endl;
		return 0;
	}
	
	string b;
	for(int i=0; i<n; ++i) {
		while(k && b.size() && b.back() > a[i]) {
			b.pop_back();
			--k;
		}
		b += a[i];
	}
	
	while(k--) b.pop_back();
	//去除前导零
	reverse(b.begin(), b.end());
	while(b.size() > 1 && b.back() == '0') b.pop_back();
	reverse(b.begin(), b.end());
	
	cout << b << endl;
	
	return 0;
}
