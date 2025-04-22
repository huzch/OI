#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e3 + 10;
int f[N];
int v[N], w[N];
int n, V;

int main() {
	cin >> n >> V;
	for(int i=1; i<=n; ++i) {
		cin >> v[i] >> w[i];
	}

	for(int i=1; i<=n; ++i) {
		for(int j=V; j>=v[i]; --j) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	cout << f[V] << endl;

	memset(f, -0x3f, sizeof f);
	f[0] = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=V; j>=v[i]; --j) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	if(f[V] < 0) cout << 0 << endl;
	else cout << f[V] << endl;

	return 0;
}




//#include<iostream>
//#include<cstring>
//using namespace std;
//
//const int N = 1e3 + 10;
////f[i][j]:前i个物品中，总体积不超过j时，所装的最大价值
////f[i][j]:前i个物品中，总体积必须为j时，所装的最大价值
//int f[N][N];
//int v[N], w[N];
//int n, V;
//
//int main() {
//	cin >> n >> V;
//	for(int i=1; i<=n; ++i) {
//		cin >> v[i] >> w[i];
//	}
//	
//	for(int i=1; i<=n; ++i) {
//		for(int j=0; j<=V; ++j) {
//			if(j >= v[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
//			else f[i][j] = f[i - 1][j];
//		}
//	}
//	cout << f[n][V] << endl;
//	
//	memset(f, -0x3f, sizeof f);
//	f[0][0] = 0;
//	for(int i=1; i<=n; ++i) {
//		for(int j=0; j<=V; ++j) {
//			if(j >= v[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
//			else f[i][j] = f[i - 1][j];
//		}
//	}
//	if(f[n][V] < 0) cout << 0 << endl;
//	else cout << f[n][V] << endl;
//	
//	return 0;
//}
