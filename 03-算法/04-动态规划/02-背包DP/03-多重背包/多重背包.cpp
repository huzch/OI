//二进制优化，但是不能用于求方案数
#include<iostream>
using namespace std;

const int N = 110 * 5;//乘以x数据范围的位数
int v[N], w[N];
int f[N];
int cnt;
int n, T;

int main() {
	cin >> n >> T;
	for(int i=1; i<=n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		
		int t = 1;
		while(x >= t) {
			++cnt;
			v[cnt] = y * t;
			w[cnt] = z * t;
			x -= t;
			t *= 2;
		}
		//若x有剩余
		if(x) {
			++cnt;
			v[cnt] = y * x;
			w[cnt] = z * x;
		}
	}
	
	//分组背包转化为01背包
	for(int i=1; i<=cnt; ++i) {
		for(int j=T; j>=v[i]; --j) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	cout << f[T] << endl;
	
	return 0;
}




//#include<iostream>
//using namespace std;
//
//const int N = 110;
//int x[N], v[N], w[N];
////f[i][j]:在前i个物品中挑选，总重量不超过j时，所选的最大价值
//int f[N];
//int n, T;
//
//int main() {
//	cin >> n >> T;
//	for(int i=1; i<=n; ++i) {
//		cin >> x[i] >> v[i] >> w[i];
//	}
//	
//	for(int i=1; i<=n; ++i) {
//		for(int j=T; j>=0; --j) {
//			for(int k=1; k<=x[i] && k*v[i]<=j; ++k) {
//				f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
//			}
//		}
//	}
//	cout << f[T] << endl;
//	
//	return 0;
//}
