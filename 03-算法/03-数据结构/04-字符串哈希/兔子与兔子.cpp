#include<iostream>
using namespace std;

typedef unsigned long long ULL;
const int N = 1e6 + 10;
const int P = 131;
ULL f[N], p[N];
string s;
int n, m;

void init_hash() {
	p[0] = 1;
	for(int i=1; i<=n; ++i) {
		f[i] = f[i - 1] * P + s[i];
		p[i] = p[i - 1] * P;
	}
}

ULL get_hash(int l, int r) {
	return f[r] - f[l - 1] * p[r - l + 1];
}

int main() {
	cin >> s >> m;
	n = s.size();
	s = " " + s;
	
	init_hash();
	
	while(m--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		ULL t1 = get_hash(l1, r1);
		ULL t2 = get_hash(l2, r2);
		if(t1 == t2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
