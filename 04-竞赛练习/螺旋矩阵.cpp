#include<iostream>
using namespace std;

int dfs(int begin, int n, int i, int j) {
	if(i == 1) return begin + j;
	if(j == n) return begin + n - 1 + i;
	if(i == n) return begin + 3 * n - 1 - j;
	if(j == 1) return begin + 4 * n - 2 - i;
	
	//剥去最外层，继续去内层矩阵寻找
	return dfs(begin + 4 * (n - 1), n - 2, i - 1, j - 1);
}

int main() {
	int n, i, j; cin >> n >> i >> j;
	
	cout << dfs(0, n, i, j) << endl;
	
	return 0;
}
