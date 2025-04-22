#include<iostream>
using namespace std;

const int N = 20;
int a[N];

int main() {
	for(int i=1; i<=10; ++i) cin >> a[i];
	int x; cin >> x;
	
	int cnt = 0;
	for(int i=1; i<=10; ++i) {
		if(a[i] <= x + 30) ++cnt;
	}
	cout << cnt << endl;
	
	return 0;
}
