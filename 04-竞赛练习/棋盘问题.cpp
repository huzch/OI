#include<iostream>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	
	int ret1 = 0, ret2 = 0;
	for(int x1=0; x1<=n; ++x1) {
		for(int y1=0; y1<=m; ++y1) {
			for(int x2=x1+1; x2<=n; ++x2) {
				for(int y2=y1+1; y2<=m; ++y2) {
					if(x2 - x1 == y2 - y1) {
						++ret1;
					}
					else ++ret2;
				}
			}
		}
	}
	cout << ret1 << " " << ret2 << endl;
	
	return 0;
}
