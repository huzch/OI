//解法二：归并排序 --- 逆序对
#include<iostream>
using namespace std;

typedef long long LL;
const int N = 5e5 + 10;
int a[N], tmp[N];
LL ret;

void merge(int l, int r) {
	if(l == r) return;
	
	int mid = l + (r - l) / 2;
	merge(l, mid);
	merge(mid + 1, r);
	
	int cur1 = l, cur2 = mid + 1, k = 0;
	while(cur1 <= mid && cur2 <= r) {
		if(a[cur1] <= a[cur2]) {
			tmp[k++] = a[cur1++];
		}
		else {
			ret += mid - cur1 + 1;
			tmp[k++] = a[cur2++];
		}
	}
	
	while(cur1 <= mid) tmp[k++] = a[cur1++];
	while(cur2 <= r) tmp[k++] = a[cur2++];
	for(int i=0; i<k; ++i) a[l + i] = tmp[i];
}

int main() {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}

	merge(1, n);
	cout << ret << endl;

	return 0;
}

//解法一：冒泡排序 --- 超时
//#include<iostream>
//using namespace std;
//
//const int N = 5e5 + 10;
//int a[N];
//
//int main() {
//	int n; cin >> n;
//	for(int i=1; i<=n; ++i) {
//		cin >> a[i];
//	}
//	
//	int ans = 0;
//	for(int i=n-1; i>=1; --i) {
//		for(int j=1; j<=i; ++j) {
//			if(a[j] > a[j + 1]) {
//				swap(a[j], a[j + 1]);
//				++ans;
//			}
//		}
//	}
//	cout << ans << endl;
//	
//	return 0;
//}
