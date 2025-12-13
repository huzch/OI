#include<iostream>
#include<utility>
using namespace std;

const int N = 3e6 + 10; //输入字符串总长度
int tr[N][62], p[N];
int id;

int get_num(char ch) {
	if(islower(ch)) return ch - 'a';
	if(isupper(ch)) return ch - 'A' + 26;
	return ch - '0' + 52; //if(isdigit(ch))
}

void insert(string& s) {
	int cur = 0;
	++p[cur];
	
	for(char ch: s) {
		int path = get_num(ch);
		if(tr[cur][path] == 0) tr[cur][path] = ++id;
		cur = tr[cur][path];
		++p[cur];
	}
}

int find_pre(string& s) {
	int cur = 0;
	
	for(char ch: s) {
		int path = get_num(ch);
		if(tr[cur][path] == 0) return 0;
		cur = tr[cur][path];
	}
	return p[cur];
}

int main() {
	int T; cin >> T;
	
	while(T--) {
		//清空数据
		//由于空间达到1e8，频繁清空会超时，所以手动清空
		for(int i=0; i<=id; ++i) {
			for(int j=0; j<62; ++j) {
				tr[i][j] = 0;
			}
		}
		for(int i=0; i<=id; ++i) p[i] = 0;
		id = 0;
		
		int n, q; cin >> n >> q;
		
		while(n--) {
			string s; cin >> s;
			insert(s);
		}
		
		while(q--) {
			string s; cin >> s;
			cout << find_pre(s) << endl;
		}
	}
	
	return 0;
}
