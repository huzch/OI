#include<iostream>
using namespace std;

const int N = 110;
char a[N];
int n;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	
	if(n % 2 == 0) {
		for(int i=1; i<=n; ++i) {
			cout << a[i];
			if(i != n && i % 2 == 0) cout << '-';
		}
	}
	else {
		for(int i=1; i<=3; ++i) {
			cout << a[i];
		}
		if(n > 3) cout << '-';

  		for(int i=4; i<=n; ++i) {
			cout << a[i];
			if(i != n && i % 2 != 0) cout << '-';
		}
	}
	return 0;
}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//vector<string> ret;
//string s, path;
//int n;
//
//void dfs(int pos) {
//	if(pos > n) return;
//	if(pos == n) {
//		path.pop_back();
//		ret.push_back(path);
//		return;
//	}
//	
//	int sz = path.size();
//	
//	path += s.substr(pos, 2) + '-';
//	dfs(pos + 2);
//	path.resize(sz);
//	
//	path += s.substr(pos, 3) + '-';
//	dfs(pos + 3);
//	path.resize(sz);
//}
//
//int main() {
//	cin >> n >> s;
//	
//	dfs(0);
//	
//	cout << ret[0] << endl;
//	
//	return 0;
//}
