#include <iostream>
#include <utility>
using namespace std;

const int N = 1e6 + 10;
int a[N], b[N], c[N];
int la, lb, lc;

bool cmp(string& x, string& y) {
	if(x.size() != y.size()) return x.size() < y.size();
	return x < y;
}

void sub() {
	for(int i=0; i<lc; ++i) {
		c[i] += a[i] - b[i];
		if(c[i] < 0) {
			c[i] += 10;
			c[i + 1] -= 1;
		}
	}

	while(lc > 1 && c[lc - 1] == 0) --lc;
}

int main() {
	string x, y; cin >> x >> y;

	if(cmp(x, y)) {
		swap(x, y);
		cout << '-';
	}

	la = x.size(), lb = y.size(), lc = max(la, lb);
	for(int i=0; i<la; ++i) a[la - i - 1] = x[i] - '0';
	for(int i=0; i<lb; ++i) b[lb - i - 1] = y[i] - '0';

	sub();

	for(int i=lc-1; i>=0; --i) cout << c[i];

	return 0;
}
