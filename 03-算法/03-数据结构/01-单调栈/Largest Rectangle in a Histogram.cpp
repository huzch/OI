#include<iostream>
#include<stack>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
LL a[N], l[N], r[N];
int n;

stack<int> st;

int main() {
	while(cin >> n && n) {
		for(int i=1; i<=n; ++i) {
			cin >> a[i];
		}
		
		while(st.size()) st.pop();
		for(int i=n; i>=1; --i) {
			while(st.size() && a[st.top()] >= a[i]) st.pop();
			if(st.size()) r[i] = st.top();
			else r[i] = n + 1;
			st.push(i);
		}
		
		while(st.size()) st.pop();
		for(int i=1; i<=n; ++i) {
			while(st.size() && a[st.top()] >= a[i]) st.pop();
			if(st.size()) l[i] = st.top();
			else l[i] = 0;
			st.push(i);
		}
		
		LL ret = 0;
		for(int i=1; i<=n; ++i) {
			LL s = (r[i] - l[i] - 1) * a[i];
			ret = max(ret, s);
		}
		cout << ret << endl;
	}
	return 0;
}
