#include <cctype>
#include <iostream>
#include <stack>
using namespace std;

int main() {
	string s; cin >> s;
	stack<int> nums;
	int n = s.size();
	for(int i=0; i<n; ++i) {
		char ch = s[i];
		if(isdigit(ch)) {
			int x = 0;
			while(i < n && isdigit(s[i])) {
				x = x * 10 + s[i] - '0';
				++i;
			}
			--i;
			nums.push(x);
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			int x2 = nums.top(); nums.pop();
			int x1 = nums.top(); nums.pop();
			if(ch == '+') nums.push(x1 + x2);
			else if(ch == '-') nums.push(x1 - x2);
			else if(ch == '*') nums.push(x1 * x2);
			else if(ch == '/') nums.push(x1 / x2);
		}
	}
	cout << nums.top() << endl;
	return 0;
}
