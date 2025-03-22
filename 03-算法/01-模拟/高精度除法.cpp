#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1e6 + 10;
int a[N], b, c[N];
int la, lc;

//高精度/低精度
void div() {
	LL t = 0; //余数
	for(int i=la-1; i>=0; --i) {
		t = t * 10 + a[i];
		c[i] = t / b;
		t %= b;
	}

	while(lc > 1 && c[lc - 1] == 0) --lc;
}

int main() {
	string x; cin >> x >> b;

	la = x.size(), lc = la;
	for(int i=0; i<la; ++i) a[la - i - 1] = x[i] - '0';

	div();

	for(int i=lc-1; i>=0; --i) cout << c[i];

	return 0;
}
