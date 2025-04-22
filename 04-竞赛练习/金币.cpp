#include<iostream>
using namespace std;

typedef long long LL;
LL sum;

int main() {
	int k; cin >> k;
	
	int coin = 1, cnt = 0;
	for(int i=1; i<=k; ++i) {
		sum += coin;
		++cnt;
		if(cnt == coin) {
			cnt = 0;
			++coin;
		}
	}
	
	cout << sum << endl;
	
	return 0;
}
