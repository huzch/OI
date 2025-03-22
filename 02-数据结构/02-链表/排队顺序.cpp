#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int ne[N], h;
int n;

void print() {
	for(int i=h; i; i=ne[i]) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> ne[i];
	}
	cin >> h;

	print();
	return 0;
}
