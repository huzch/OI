#include<iostream>
using namespace std;

const int N = 4e6 + 10;
int tr[N][2], e[N]; //01字典树
int id;

int a[N];
int n;

void insert(int x) {
	int cur = 0;
	
	for(int i=31; i>=0; --i) {
		int path = (x >> i) & 1;
		if(tr[cur][path] == 0) tr[cur][path] = ++id;
		cur = tr[cur][path];
	}
	
	e[cur] = x; //这里end直接存储数，方便后续异或
}

int find(int x) {
	int cur = 0;
	
	for(int i=31; i>=0; --i) {
		int path = ((x >> i) & 1) ^ 1;
		if(tr[cur][path] == 0) path ^= 1; //贪心，退而求其次
		cur = tr[cur][path];
	}
	
	return e[cur] ^ x;
}

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i]; //测试数据都是正数，不考虑负数
		insert(a[i]);
	}
	
	int ret = 0;
	for(int i=1; i<=n; ++i) {
		int t = find(a[i]);
		ret = max(ret, t);
	}
	cout << ret << endl;
	
	return 0;
}
