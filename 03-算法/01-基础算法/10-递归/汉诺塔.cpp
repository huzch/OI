#include <cstdio>
#include <iostream>
using namespace std;

void Hanoi(int n, char a, char b, char c) {
	if(n == 0) return;

	Hanoi(n - 1, a, c, b);
	printf("%c->%d->%c\n", a, n, c);
	Hanoi(n - 1, b, a, c);
}

int main() {
	int n; cin >> n;
	char x, y, z; cin >> x >> y >> z;

	Hanoi(n, x, z, y);

	return 0;
}
