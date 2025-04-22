#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int n;

int main() {
	cin >> n;
	for(int i=0; i<n; ++i) cin >> a[i];
	
	int ret = 0;
	bool flag = false;
	for(int i=0; i<n; ++i) {
		if(a[i] == i) ++ret;
		else if(a[a[i]] == i) flag = true;
	}
	
	if(ret == n) cout << ret << endl;
	else {
		if(flag) ++ret;
		cout << ret + 1 << endl;
	}
	
	return 0;
}
