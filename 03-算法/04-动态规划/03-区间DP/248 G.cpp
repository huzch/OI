#include<iostream>
using namespace std;

const int N = 250;
int a[N];
//f[i][j]:将区间[i,j]合并为一个数时，所得的最大值
int f[N][N];
int n;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		f[i][i] = a[i];
	}

	for(int len=2; len<=n; ++len) {
		for(int i=1; i+len-1<=n; ++i) {
			int j = i + len - 1;
			for(int k=i; k<j; ++k) {
				//f[i][j]为0，则表示不能合并为一个数
				if(f[i][k] && f[i][k] == f[k + 1][j]) {
					f[i][j] = max(f[i][j], f[i][k] + 1);
				}
			}
		}
	}

 	//由于区间[1,n]可能不能合并为一个数，所以更新结果要查看所有区间
	int ret = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=i; j<=n; ++j) {
		    ret = max(ret, f[i][j]);
		}
	}
	cout << ret << endl;
	
	return 0;
}
