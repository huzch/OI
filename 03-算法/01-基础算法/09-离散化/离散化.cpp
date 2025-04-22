//模板一：排序+去重+二分
// #include <algorithm>
// #include <iostream>
// using namespace std;
//
// const int N = 1e5 + 10;
// int a[N], n;
// int disc[N], pos;
//
// int find(int x) {
// 	int l = 1, r = pos;
// 	while(l < r) {
// 		int mid = l + (r - l) / 2;
// 		if(disc[mid] >= x) r = mid;
// 		else l = mid + 1;
// 	}
// 	return l;
// }
//
// int main() {
// 	cin >> n;
// 	for(int i=1; i<=n; ++i) {
// 		cin >> a[i];
// 		disc[++pos] = a[i];
// 	}
//
// 	sort(disc + 1, disc + pos + 1);
// 	pos = unique(disc + 1, disc + pos + 1) - (disc + 1);
//
// 	for(int i=1; i<=n; ++i) {
// 		cout << a[i] << "->" << find(a[i]) << endl;
// 	}
// 	return 0;
// }




//模板二：排序+哈希表
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 10;
int a[N], n;
int disc[N], pos;
unordered_map<int, int> mp;

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		disc[++pos] = a[i];
	}

	sort(disc + 1, disc + pos + 1);
	int k = 0;
	for(int i=1; i<=pos; ++i) {
		int x = disc[i];
		if(mp.count(x)) continue;
		mp[x] = ++k;
	}

	for(int i=1; i<=n; ++i) {
		cout << a[i] << "->" << mp[a[i]] << endl;
	}
	return 0;
}
