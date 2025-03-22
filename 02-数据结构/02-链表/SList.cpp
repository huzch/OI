#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int e[N], ne[N], h, id;
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
	ne[h] = id;
}

void insert(int p, int x) {
	e[++id] = x;
	mp[x] = id;
	ne[id] = ne[p];
	ne[p] = id;
}

void erase(int p) {
	//确保下一个结点不为空
	if(ne[p]) {
		mp[e[ne[p]]] = 0; //清空删除结点的mp映射
		ne[p] = ne[ne[p]];
	}
}

int find(int x) {
	//1.遍历查找
	// for(int i=ne[h]; i; i=ne[i]) {
	// 	if(e[i] == x) return i;
	// }
	// return 0;
	
	//2.mp数组优化
	return mp[x];
}

int main() {
	push_front(1);
	push_front(2);
	push_front(3);
	push_front(4);
	push_front(5);
	print();

	// cout << find(1) << endl;
	// cout << find(3) << endl;
	
	insert(1, 6);
	insert(2, 7);
	insert(3, 8);
	print();

	erase(3);
	print();
	
	return 0;
}
