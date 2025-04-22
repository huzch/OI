#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
using namespace std;

const int N = 5e6 + 10;
int a[N];
int n, k;

int get_random(int l, int r) {
	return a[l + rand() % (r - l + 1)];
}

int quick_select(int left, int right, int k) {
	if(left == right) return a[left];

	int key = get_random(left, right);

	int l = left - 1, r = right + 1, i = left;
	while(i < r) {
		if(a[i] < key) swap(a[++l], a[i++]);
		else if(a[i] == key) ++i;
		else swap(a[--r], a[i]);
	}

	int a = l - left + 1, b = r - l - 1;
	if(k <= a) return quick_select(left, l, k);
	else if(k <= a + b) return key;
	else return quick_select(r, right, k - a - b);
}

int main() {
	// cin >> n >> k;
	// for(int i=1; i<=n; ++i) cin >> a[i];
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i) scanf("%d", &a[i]);

	srand(time(0));
	//题目要求：最小为第0小
	cout << quick_select(1, n, k + 1) << endl;

	return 0;
}
