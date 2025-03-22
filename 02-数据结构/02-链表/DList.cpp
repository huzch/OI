#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int e[N], ne[N], pre[N], h, id;
int mp[N];

void print() {
	for(int i=ne[h]; i; i=ne[i]) {
		cout << e[i] << " ";
	}
	cout << endl;
}

void push_front(int x) {
	e[++id] = x;
	mp[x] = id;
	ne[id] = ne[h];
	pre[id] = h;
	pre[ne[h]] = id;
	ne[h] = id;
}

void insert_back(int p, int x) {
	e[++id] = x;
	mp[x] = id;
	ne[id] = ne[p];
	pre[id] = p;
	pre[ne[p]] = id;
	ne[p] = id;
}

void insert_front(int p, int x) {
	e[++id] = x;
	mp[x] = id;
	ne[id] = p;
	pre[id] = pre[p];
	ne[pre[p]] = id;
	pre[p] = id;
}

void erase(int p) {
	mp[e[p]] = 0;
	ne[pre[p]] = ne[p];
	if(ne[p]) pre[ne[p]] = pre[p];
}

int find(int x) {
	return mp[x];
}

int main() {
	push_front(1);
	push_front(2);
	push_front(3);
	push_front(4);
	push_front(5);
	print();

	cout << find(5) << endl;

	insert_front(1, 2);
	insert_front(2, 3);
	insert_front(3, 4);
	print();

	erase(2);
	erase(4);
	erase(5);
	print();
	
	return 0;
}
