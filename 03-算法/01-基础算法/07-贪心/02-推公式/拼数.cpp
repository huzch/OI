#include <algorithm>
#include <iostream>
using namespace std;

const int N = 30;
string a[N];

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];

	sort(a + 1, a + n + 1, [](string& x, string& y){
		return x + y > y + x;
	});

	for(int i=1; i<=n; ++i) cout << a[i];
	return 0;
}
