#include<iostream>
#include<cctype>
using namespace std;

int main() {
	string s; cin >> s;
	
	int ret = 0, k = 1;
	int n = s.size();
	for(int i=0; i<n-1; ++i) {
		char ch = s[i];
		if(isdigit(ch)) {
			ret += (ch - '0') * k;
			++k;
		}
	}

	ret %= 11;
	if(ret == s[n - 1] - '0' || (ret == 10 && s[n - 1] == 'X')) {
		cout << "Right" << endl;
	}
	else {
		if(ret == 10) s[n - 1] = 'X';
		else s[n - 1] = ret + '0';
		cout << s << endl;
	}
	
	return 0;
}
