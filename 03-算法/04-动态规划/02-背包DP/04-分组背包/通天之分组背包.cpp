#include<iostream>
#include<vector>
using namespace std;

const int N = 1e3 + 10;
struct node {
	int v, w;
};
vector<node> a[N];
//f[i][j]:在前i组中挑选，总重量不超过j时，所有的最大价值
int f[N];
int n, m;
int cnt;

int main() {
	cin >> m >> n;
	for(int i=1; i<=n; ++i) {
		int x, y, z; cin >> x >> y >> z;
		a[z].push_back({x, y});
		cnt = max(cnt, z);
	}
	
	for(int i=1; i<=cnt; ++i) {
		for(int j=m; j>=0; --j) {
			for(auto& t: a[i]) {
				if(j >= t.v) f[j] = max(f[j], f[j - t.v] + t.w);
			}
		}
	}
	cout << f[m] << endl;
	
	return 0;
}
