#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int stk[N], n;

void push(int x) {
	stk[++n] = x;
}

void pop() {
	--n;
}

int top() {
	return stk[n];
}

bool empty() {
	return n == 0;
}

int size() {
	return n;
}

int main() {
	for(int i=1; i<=10; ++i) {
		push(i);
	}

	while(!empty()) {
		int x = top();
		pop();
		cout << x << " ";
	}
	return 0;
}
