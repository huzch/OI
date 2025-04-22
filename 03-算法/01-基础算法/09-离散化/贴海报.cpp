#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 1e3 + 10;
int a[N], b[N];
int disc[4 * N], pos;
int w[4 * N];

//二分
int find(int x) {
	int l = 1, r = pos;
	while(l < r) {
		int mid = l + (r - l) / 2;
		if(disc[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	int n, m; cin >> n >> m;
	for(int i=1; i<=m; ++i) {
		cin >> a[i] >> b[i];
		//防止离散化后区间覆盖，额外添加 a + 1 与 b + 1 增加间隔
		disc[++pos] = a[i], disc[++pos] = a[i] + 1;
		disc[++pos] = b[i], disc[++pos] = b[i] + 1;
	}

	//离散化
	sort(disc + 1, disc + pos + 1);
	pos = unique(disc + 1, disc + pos + 1) - (disc + 1);

	int k = 1;
	for(int i=1; i<=m; ++i) {
		int l = find(a[i]), r = find(b[i]);
		for(int j=l; j<=r; ++j) w[j] = k;
		++k;
	}

	//统计结果
	int ret = 0;
	unordered_set<int> s;
	for(int i=1; i<=pos; ++i) {
		int x = w[i];
		if(x == 0 || s.count(x)) continue;
		s.insert(x);
		++ret;
	}
	cout << ret << endl;
	
	return 0;
}
