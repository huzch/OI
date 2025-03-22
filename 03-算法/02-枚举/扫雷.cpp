#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e4 + 10;
int a[N], b[N];

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> b[i];
	}

	// 枚举第一个格子是否有雷
	int flag1 = 1;
	for (int i=2; i<=n; ++i) {
		a[i] = b[i - 1] - a[i - 1] - a[i - 2];
		if(a[i] < 0 || a[i] > 1) {
			flag1 = 0;
			break;
		}
	}
	if(a[n - 1] + a[n] != b[n]) flag1 = 0;

	memset(a, 0, sizeof a);
	int flag2 = 1;
	a[1] = 1;
	for (int i=2; i<=n; ++i) {
		a[i] = b[i - 1] - a[i - 1] - a[i - 2];
		if(a[i] < 0 || a[i] > 1) {
			flag2 = 0;
			break;
		}
	}
	if(a[n - 1] + a[n] != b[n]) flag2 = 0;

	cout << flag1 + flag2;

	return 0;
}
