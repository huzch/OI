#include<iostream>
using namespace std;

const int N = 110;
int a[N];

int main() {
	int n; cin >> n;
	
	int x = 0;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		x += a[i];
	}
	x /= n;
	
	//贪心：从前往后判断当前位置是否为平均数，若不为则补全
	int ret = 0;
	for(int i=1; i<n; ++i) {
		if(a[i] == x) continue;
		a[i + 1] -= x - a[i];
		++ret;
	}
	cout << ret << endl;
	
	return 0;
}
