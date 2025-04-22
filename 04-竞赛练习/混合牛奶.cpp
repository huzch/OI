#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 2e6 + 10;
struct node {
	int p, q;
}a[N];
int n, m;

int main() {
	cin >> n >> m;
	for(int i=1; i<=m; ++i) {
		cin >> a[i].p >> a[i].q;
	}
	
	sort(a + 1, a + m + 1, [](node& x, node& y){
		return x.p < y.p;
	});
	
	LL ret = 0, sum = 0;
	for(int i=1; i<=m; ++i) {
		if(sum + a[i].q < n) {
			sum += a[i].q;
			ret += a[i].p * a[i].q;
		}
		else {
			ret += a[i].p * (n - sum);
			break;
		}
	}
	cout << ret << endl;
	
	return 0;
}
