#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();
	vector<bool> paired(n);
	stack<int> st;
	for(int i=0; i<n; ++i) {
		char ch = s[i];
		if(ch == '(' || ch == '[') {
			st.push(i);
		}
		else {
			if(st.empty()) continue;
			auto j = st.top();
			if((s[j] == '(' && ch == ')') 
			|| (s[j] == '[' && ch == ']')) {
				paired[j] = paired[i] = true;
				st.pop();
			}
		}
	}

	for(int i=0; i<n; ++i) {
		char ch = s[i];
		if(!paired[i]) {
			if(ch == '(' || ch == ')') {
				cout << "()";
			} 
			else if(ch == '[' || ch == ']') {
				cout << "[]";
			}
		}
		else cout << ch;
	}
	cout << endl;

	return 0;
}
