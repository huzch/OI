// #include <iostream>
// using namespace std;
//
// const int N = 1e5 + 10;
// int st[N], top;
// int pushed[N], poped[N];
// int n, q;
//
// int main() {
// 	cin >> q;
// 	while(q--) {
// 		cin >> n;
// 		for(int i=1; i<=n; ++i) {
// 			cin >> pushed[i];
// 		}
// 		for(int i=1; i<=n; ++i) {
// 			cin >> poped[i];
// 		}
//
// 		int j = 1;
// 		top = 0;
// 		for(int i=1; i<=n; ++i) {
// 			st[++top] = pushed[i];
// 			while(top && st[top] == poped[j]) {
// 				--top;
// 				++j;
// 			}
// 		}
//
// 		if(top == 0) {
// 			cout << "Yes" << endl;
// 		}
// 		else {
// 			cout << "No" << endl;
// 		}
// 	}
// 	return 0;
// }







// #include <cctype>
// #include <iostream>
// #include <stack>
// using namespace std;
//
// int main() {
// 	string s; cin >> s;
// 	stack<int> nums;
// 	int n = s.size();
// 	for(int i=0; i<n; ++i) {
// 		char ch = s[i];
// 		if(isdigit(ch)) {
// 			int x = 0;
// 			while(i < n && isdigit(s[i])) {
// 				x = x * 10 + s[i] - '0';
// 				++i;
// 			}
// 			--i;
// 			nums.push(x);
// 		}
// 		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
// 			int x2 = nums.top(); nums.pop();
// 			int x1 = nums.top(); nums.pop();
// 			if(ch == '+') nums.push(x1 + x2);
// 			else if(ch == '-') nums.push(x1 - x2);
// 			else if(ch == '*') nums.push(x1 * x2);
// 			else if(ch == '/') nums.push(x1 / x2);
// 		}
// 	}
// 	cout << nums.top() << endl;
// 	return 0;
// }







// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;
//
// int main() {
// 	string s; cin >> s;
// 	int n = s.size();
// 	vector<bool> paired(n);
// 	stack<int> st;
// 	for(int i=0; i<n; ++i) {
// 		char ch = s[i];
// 		if(ch == '(' || ch == '[') {
// 			st.push(i);
// 		}
// 		else {
// 			if(st.empty()) continue;
// 			auto j = st.top();
// 			if((s[j] == '(' && ch == ')') 
// 			|| (s[j] == '[' && ch == ']')) {
// 				paired[j] = paired[i] = true;
// 				st.pop();
// 			}
// 		}
// 	}
//
// 	for(int i=0; i<n; ++i) {
// 		char ch = s[i];
// 		if(!paired[i]) {
// 			if(ch == '(' || ch == ')') {
// 				cout << "()";
// 			} 
// 			else if(ch == '[' || ch == ']') {
// 				cout << "[]";
// 			}
// 		}
// 		else cout << ch;
// 	}
// 	cout << endl;
//
// 	return 0;
// }





// #include <iostream>
// using namespace std;
//
// const int N = 1e4 + 10;
// int q[N], h, t;
//
// int main() {
// 	int n; cin >> n;
// 	while(n--) {
// 		int op; cin >> op;
// 		if(op == 1) {
// 			int x; cin >> x;
// 			q[++t] = x;
// 		}
// 		else if(op == 2) {
// 			if(h == t) {
// 				cout << "ERR_CANNOT_POP" << endl;
// 			}
// 			else ++h;
// 		}
// 		else if(op == 3) {
// 			if(h == t) {
// 				cout << "ERR_CANNOT_QUERY" << endl;
// 			}
// 			else {
// 				cout << q[h + 1] << endl;
// 			}
// 		}
// 		else if(op == 4) {
// 			cout << t - h << endl;
// 		}
// 	}
// 	return 0;
// }
//


// #include <iostream>
// using namespace std;
//
// const int N = 1e3 + 10;
// int q[N], h, t;
// bool st[N];
// int m, n, cnt;
//
// int main() {
// 	cin >> m >> n;
// 	while(n--) {
// 		int x; cin >> x;
// 		if(!st[x]) {
// 			if(t - h == m) {
// 				++h;
// 				st[q[h]] = false;
// 			}
// 			q[++t] = x;
// 			st[x] = true;
// 			++cnt;
// 		}
// 	}
// 	cout << cnt << endl;
// 	return 0;
// }
//



//
// #include <iostream>
// #include <queue>
// #include <utility>
// using namespace std;
//
// typedef pair<int, int> PII;
// const int N = 1e5 + 10;
// queue<PII> q;
// int cnt[N], kinds;
// int n, t, k;
//
// int main() {
// 	cin >> n;
// 	while(n--) {
// 		cin >> t >> k;
// 		while(k--) {
// 			int x; cin >> x;
// 			q.push({t, x});
// 			if(cnt[x]++ == 0) {
// 				++kinds;
// 			}
// 			while(q.size()) {
// 				PII front = q.front();
// 				if(front.first + 86400 <= t) {
// 					q.pop();
// 					if(--cnt[front.second] == 0) {
// 						--kinds;
// 					}
// 				}
// 				else break;
// 			}
// 		}
// 		cout << kinds << endl;
// 	}
// 	return 0;
// }















#include <iostream>
using namespace std;

const int N = 300;
char l[N], r[N];
int n;
char root, t;

void dfs(char u) {
	if(u == '*') return;
	cout << u;
	dfs(l[u]);
	dfs(r[u]);
}

int main() {
	cin >> n;
	cin >> root >> l[root] >> r[root];
	for(int i=2; i<=n; ++i) {
		cin >> t >> l[t] >> r[t];
	}

	dfs(root);

	return 0;
}










