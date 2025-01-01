#include <iostream>
#include <utility>
using namespace std;

const int N = 1e5 + 10;
int hp[N], n;

void up(int child) {
	int parent = child / 2;
	while(parent >= 1) {
		if(hp[parent] < hp[child]) {
			swap(hp[parent], hp[child]);
			child = parent;
			parent = child / 2;
		}
		else break;
	}
}

void down(int parent) {
	int child = parent * 2;
	while(child <= n) {
		if(child + 1 <= n && hp[child] < hp[child + 1]) {
			++child;
		}

		if(hp[parent] < hp[child]) {
			swap(hp[parent], hp[child]);
			parent = child;
			child = parent * 2;
		}
		else break;
	}
}

void push(int x) {
	hp[++n] = x;
	up(n);
}

void pop() {
	swap(hp[1], hp[n--]);
	down(1);
}

int top() {
	return hp[1];
}

int size() {
	return n;
}

int main() {
	int a[10] = {1, 41, 23, 10, 11, 2, -1, 99, 14, 0};

	for(int i=0; i<10; ++i) {
		push(a[i]);
	}

	while(size()) {
		cout << top() << " ";
		pop();
	}
	cout << endl;

	return 0;
}
