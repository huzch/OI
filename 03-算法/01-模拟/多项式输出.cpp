#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	for(int i=n; i>=0; --i) {
		int a; cin >> a;
		// 符号
		if(a == 0) continue;
		else if(a < 0) printf("-");
		else {
			if(i != n) printf("+");
		}
		// 系数与次数
		a = abs(a);
		if(i == 0) printf("%d", a);
		else if(i == 1) {
			if(a == 1) printf("x");
			else printf("%dx", a);
		}
		else {
			if(a == 1) printf("x^%d", i);
			else printf("%dx^%d", a, i);
		}
	}
	return 0;
}
