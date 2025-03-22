#include <iostream>
#include <unordered_map>
using namespace std;

string a, b;
unordered_map<char, int> mp;

void dfs(int l1, int r1, int l2, int r2) {
	if(l1 > r1) return;
	//1.寻找根结点
	cout << b[r2];
	int p = mp[b[r2]];
	//2.划分左右子树
	dfs(l1, p - 1, l2, l2 + p - l1 - 1);
	dfs(p + 1, r1, l2 + p - l1, r2 - 1);
}

int main() {
	cin >> a >> b;
	int n = a.size();
	for(int i=0; i<n; ++i) {
		mp[a[i]] = i;
	}

	dfs(0, n - 1, 0, n - 1);
	return 0;
}
