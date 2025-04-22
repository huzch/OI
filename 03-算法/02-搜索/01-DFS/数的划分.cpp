#include<iostream>
using namespace std;

int n, k;
int ret, sum;

void dfs(int pos, int begin) {
	if(pos == k) {
		if(sum == n) ++ret;
		return;
	}
	
	for(int i=begin; i<=n; ++i) {
  		//可行性剪枝（在未进入之前剪枝）
		if(sum + (k - pos) * i > n) return;
		sum += i;
		dfs(pos + 1, i);
		sum -= i;
	}
}

int main() {
	cin >> n >> k;
	
	dfs(0, 1);
	cout << ret << endl;
	
	return 0;
}
