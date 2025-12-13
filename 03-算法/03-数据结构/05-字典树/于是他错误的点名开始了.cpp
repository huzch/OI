#include<iostream>
using namespace std;

const int N = 5e5 + 10;
int tr[N][26], e[N];
int id;
int n, m;

void insert(string& s) {
	int cur = 0;
	
	for(char ch: s) {
		int path = ch - 'a';
		if(tr[cur][path] == 0) tr[cur][path] = ++id;
		cur = tr[cur][path];
	}
	
	++e[cur];
}

int find(string& s) {
	int cur = 0;
	
	for(char ch: s) {
		int path = ch - 'a';
		if(tr[cur][path] == 0) return 0;
		cur = tr[cur][path];
	}
	
	return e[cur]++; //找到一次加一次
}

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		string s; cin >> s;
		insert(s);
	}
	
	cin >> m;
	for(int i=1; i<=m; ++i) {
		string s; cin >> s;
		int ret = find(s);
		if(ret == 0) cout << "WRONG" << endl;
		else if(ret == 1) cout << "OK" << endl;
		else cout << "REPEAT" << endl;
	}
	
	return 0;
}
