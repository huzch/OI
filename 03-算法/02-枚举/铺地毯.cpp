#include <iostream>
#include <vector>
using namespace std;

struct carpet {
	int a, b, c, d;
};

int main() {
	int n; cin >> n;
	vector<carpet> carpets(n + 1);
	for(int i=1; i<=n; ++i) {
		int a, b, g, k;
		cin >> a >> b >> g >> k;
		carpets[i] = {a, b, a + g, b + k};
	}

	int x, y; cin >> x >> y;
	// 逆序求覆盖在最上面的地毯
	for(int i=n; i>=1; --i) {
		if(x >= carpets[i].a && y >= carpets[i].b 
		&& x <= carpets[i].c && y <= carpets[i].d) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
