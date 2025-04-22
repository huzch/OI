#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int st[N], top;
int pushed[N], poped[N];
int n, q;

int main() {
	cin >> q;
	while(q--) {
		cin >> n;
		top = 0;
		for(int i=1; i<=n; ++i) {
			cin >> pushed[i];
		}
		for(int i=1; i<=n; ++i) {
			cin >> poped[i];
		}

		int j = 1;
		for(int i=1; i<=n; ++i) {
			st[++top] = pushed[i];
			while(top && st[top] == poped[j]) {
				--top;
				++j;
			}
		}

		if(top == 0) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}
