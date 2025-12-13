#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 10;
int a[N];
int n;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];
	
	//必须先排序再去重
	sort(a + 1, a + n + 1);
	n = unique(a + 1, a + n + 1) - (a + 1);
	
	if(n == 1) cout << -1 << endl;
	else if(n == 2) cout << a[n] % a[n - 1] << endl;
	else cout << max(a[n] % a[n - 1], a[n - 2]) << endl;
	
	return 0;
}
