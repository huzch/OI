#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 310;
LL s[N];
LL f[N][N];
int n;

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> s[i];
		s[i] += s[i - 1];
	}
	
	//注意将f初始化为正无穷，防止min取到0而舍弃正确结果
	memset(f, 0x3f, sizeof f);
	for(int i=0; i<=n; ++i) f[i][i] = 0;
	for(int len=2; len<=n; ++len) {
		for(int i=1; i+len-1<=n; ++i) {
			int j = i + len - 1;
			int sum = s[j] - s[i - 1];
			//第二种划分方式：以某个点为分割点，将区间分割为两部分
			for(int k=i; k<j; ++k) {
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sum);
			}
		}
	}
	cout << f[1][n] << endl;
	
	return 0;
}
