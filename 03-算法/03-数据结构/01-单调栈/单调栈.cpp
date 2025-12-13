#include<iostream>
#include<stack>
using namespace std;

const int N = 3e6 + 10;
int a[N];
int n;

stack<int> st;
int ret[N];

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];
	
	//左边距离最近的最大值 --- 单调递减栈
	for(int i=n; i>=1; --i) {
		while(st.size() && a[st.top()] <= a[i]) st.pop();
		if(st.size()) ret[i] = st.top();
		st.push(i);
	}
	
	for(int i=1; i<=n; ++i) {
		cout << ret[i] << " ";
	}
	cout << endl;
	
	return 0;
}
