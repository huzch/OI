#include <iostream>
#include <iterator>
using namespace std;

const int N = 1e5 + 10;
int q[N], h, t;

void push(int x) {
	q[++t] = x;
}

void pop() {
	++h;
}

int front() {
	return q[h + 1];
}

int back() {
	return q[t];
}

bool empty() {
	return h == t;
}

int size() {
	return t - h;
}

int main() {
	for(int i=1; i<=5; ++i) {
		push(i);
	}

	while(size()) {
		cout << front() << " ";
		pop();
	}
	cout << endl;

	for(int i=1; i<=5; ++i) {
		push(i);
	}

	while(size()) {
		cout << back() << " ";
		pop();
	}
	cout << endl;

	return 0;
}
