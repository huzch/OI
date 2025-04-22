#include<iostream>
using namespace std;

const int N = 10;
const int M = 1e3 + 10;
//f[i][j]:前i个砝码中，能否组成总重为j
bool f[M];
int w[] = {0 ,1, 2, 3, 5, 10, 20};
int a[N];

int main() {
	for(int i=1; i<=6; ++i) cin >> a[i];
	
	f[0] = true;
	for(int i=1; i<=6; ++i) {
		for(int j=1e3; j>=0; --j) {
			for(int k=0; k<=a[i]&&k*w[i]<=j; ++k) {
				f[j] |= f[j - k * w[i]];
			}
		}
	}
	
	int ret = 0;
	for(int j=1; j<=1e3; ++j) {
		if(f[j]) ++ret;
	}
	cout << "Total=" << ret << endl;
	
	return 0;
}
