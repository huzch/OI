#include<iostream>
#include<stack>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
LL h[N], v[N];
LL ret[N];
int n;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> h[i] >> v[i];
	}
	
	stack<int> st1;
	for(int i=1; i<=n; ++i) {
		while(st1.size() && h[st1.top()] <= h[i]) st1.pop();
		if(st1.size()) ret[st1.top()] += v[i];
		st1.push(i);
	}
	
	stack<int> st2;
	for(int i=n; i>=1; --i) {
		while(st2.size() && h[st2.top()] <= h[i]) st2.pop();
		if(st2.size()) ret[st2.top()] += v[i];
		st2.push(i);
	}
	
	LL r = 0;
	for(int i=1; i<=n; ++i) {
		r = max(r, ret[i]);
	}
	cout << r << endl;
	
	return 0;
}
