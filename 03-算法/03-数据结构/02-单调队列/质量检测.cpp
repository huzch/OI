#include<iostream>
#include<deque>
using namespace std;

const int N = 1e6 + 10;
int a[N];
int n, m;

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; ++i) cin >> a[i];
	
	deque<int> q;
	//窗口内最小值 --- 单调递增队列
	for(int i=1; i<=n; ++i) {
		while(q.size() && a[q.back()] >= a[i]) q.pop_back();
		q.push_back(i);
		if(q.back() - q.front() + 1 > m) q.pop_front();
		if(i >= m) cout << a[q.front()] << endl;
	}
	
	return 0;
}
