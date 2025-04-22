#include<iostream>
using namespace std;

const int N = 1e3 + 10;
//f[i][j]:区间[i,j]的子串，变成回文串的最小插入次数
int f[N][N];
string s;

int main() {
	cin >> s;
	int n = s.size();
	s = " " + s;
	
	for(int len=2; len<=n; ++len) {
		for(int i=1; i+len-1<=n; ++i) {
			int j = i + len - 1;
			if(s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
			else f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
		}
	}
	cout << f[1][n] << endl;
	
	return 0;
}
