#include<iostream>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;
	
	int ret = n % k;
	if(ret == 0) ret = k;
	else ret = k - ret;
	cout << ret << endl;
	
	return 0;
}
